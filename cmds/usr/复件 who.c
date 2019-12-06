// who2.c
// From ES2
// modified by wind

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>

#define ENGLISH_MUD_NAME INTERMUD_MUD_NAME
inherit F_CLEAN_UP;

int sort_user(object,object);
int help();

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string name, str, *option,str1;
        object *list, *ob, ob1;
        int i, j,ppl_cnt, cnt,wiz_cnt;
        int opt_long, opt_wiz,opt_id,opt_party;
//        int SendInterMud=0;
        string strMsg;//, HostName
        wiz_cnt = 0;

        if(remote && sizeof(arg)<2) arg="";

        if( arg ) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-h": return help();
                                case "-l": strMsg="-l",opt_long = 1;        break;
                                case "-w": strMsg="-w",opt_wiz = 1;         break;
                                case "-i": strMsg="-i";opt_id = 1; break;
                                case "-p": strMsg="-p",opt_party = 1;       break;
                                default:
/*
	                if( option[i][0]=='@' ) {
                        if( !find_object(DNS_MASTER) )
                                return notify_fail("��·���鲢û�б����룬���Ƚ���·�������롣\n");
                        SendInterMud=1;
                        HostName=sprintf("%s",option[i][1..sizeof(option[i])]);
                        break;
                        }
*/
                                        ob1 = present(option[i], environment(me));
                                        if (!ob1) ob1 = find_player(option[i]);
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if (!ob1) return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-i] [-w] [-p] [<ID>]\n"); 
                                        if( me && !me->visible(ob1) ) return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-i] [-w] [-p] [<ID>]\n");
                                        me = ob1; opt_party = 1;
                        }
        }
/*
        if (SendInterMud) {
                RWHO_Q->send_rwho_q(HostName,me, strMsg );
                write("��·ѶϢ���ͳ������Ժ�\n");
                return 1; 
                }
*/
       if( opt_long && !wizardp(me)) {
                if( (int)me->query("jing") < 5 )
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("jing", 5);
        }

    str = HIG "��" + CHINESE_MUD_NAME + HIG "��" + HIW + ENGLISH_MUD_NAME+ NOR+"Ŀǰ���ߵ�";
    if(opt_party) if(me->query("family/family_name")) str += HIR + "(" + me->query("family/family_name") + ")" +  NOR;
                        else str += HIR + "(������)" + NOR;
    if ( opt_wiz )
                str += "�����У�";
    else
        if ( opt_long ) str += "����У�";
                else
                        str += "�������У�";
        str += "\n";
        str +=HIW "�ѡ�"HIB"����������������������������������������������������������������������"HIW"�ԡ�\n"NOR;
//        ob = users();
        ob = filter_array(children(USER_OB) , (: clonep :) );
        if (opt_party) {
               ob = filter_array(ob, (: $1->query("family/family_name") ==
                        $2->query("family/family_name") :), me);
                        }
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;
        cnt = 0;
        j = sizeof(list);
        while(j--) {
                if( !environment(list[j]) ) continue;
                if( me && !me->visible(list[j]) ) continue;
                if(!me && list[j]->query("env/invisibility") > 0 ) continue;
                if( wizardp(list[j]) && (int)list[j]->query("env/invisibility") > 0 ) continue;
                if( opt_long || opt_wiz ) {
                        if( opt_wiz && !wizardp(list[j]) ) continue;
                        if( opt_wiz && (SECURITY_D->get_status(list[j]->query("id")) == "(superuser)") ) continue;//modify byp@jyqxz
                        if( (SECURITY_D->get_status(list[j]->query("id")) == "(superuser)") ) continue;
                        str = sprintf("%s%12s%s%s\n",str,RANK_D->query_rank(list[j]),
                                interactive(list[j])?(query_idle(list[j]) > 120?HIY "@" NOR:" "):HIB "#" NOR,
                                list[j]->short(1));
                        if( interactive(list[j]) ) ppl_cnt++;
                } else {
                        if( remote ) {
                                str1=list[j]->name(1)+"("+capitalize(list[j]->query("id"))+")";
                                str = sprintf("%s%-20s%s",str,str1,(ppl_cnt%3==2? "\n": "\t"));
                                ppl_cnt++;
                        } else {
                                if( wizardp(list[j]) && (int)list[j]->query("env/invisibility") > 0 ) continue;
                                if( interactive(list[j]) && query_idle(list[j]) > 150)
                                        name = sprintf( HIY"%s%-10s(%-12s"HIB"��","@",
                                                list[j]->name(1),
                                                capitalize(list[j]->query("id"))+")");
                                else if(list[j]->query_temp("netdead")) 
                                        name = sprintf( HIB"%s%-10s(%-12s"HIB"��","#",
                                                list[j]->name(1),
                                                capitalize(list[j]->query("id"))+")");
                                else 
                                        name = sprintf( HIW"%s%-10s(%-12s"HIB"��"," ",
                                                list[j]->name(1),
                                                capitalize(list[j]->query("id"))+")");
                                str = sprintf("%s%25s%s", str, name,cnt%3==2?"\n":"");
                                if( interactive(list[j]) ) ppl_cnt++;
                                cnt++;
                        }
                }// end opt
        }//end while
        if( remote ) {
                if( ppl_cnt%3 ) str += "\n";
        } else {
                if ( cnt%3 ) str += "\n";
        }

       str += HIW "�ѡ�"HIB"��������������������������������������������������"HIY"��ӹȺ����"HIB"����������"HIW"�ԡ�\n"NOR;
        str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n " + HIY"@"NOR + " ��ʾ�����У�" + HIR"#"NOR + " ��ʾ�����С�\n", str, ppl_cnt,
                query_load_average());

        if( remote ) return str;
//        if (sizeof(str)<8190) write(str);
//        else 
          me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob2)
                        - wiz_level(ob1);
        
        name1 = ob1->query("family/family_name");
        name2 = ob2->query("family/family_name");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}


int help()
{
//write(@HELP
write("
ָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]

���ָ������г����������ϵ���Ҽ���ȼ���

-h �г�������Ļ��
-l ѡ���г��ϳ���ѶϢ��
-p ֻ�г�ͬ�ŵ���ҡ�
-w ֻ�г��������е���ʦ��
<ID> �г�<ID>��������������ɵ���ҡ�

"HIY"@"NOR" ��ʾ"HIY"����"NOR"�У�"HIB"#"NOR" ��ʾ"HIB"����"NOR"�С�

���ָ� finger
"
    );
    return 1;
}

