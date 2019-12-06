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
                                return notify_fail("网路精灵并没有被载入，请先将网路精灵载入。\n");
                        SendInterMud=1;
                        HostName=sprintf("%s",option[i][1..sizeof(option[i])]);
                        break;
                        }
*/
                                        ob1 = present(option[i], environment(me));
                                        if (!ob1) ob1 = find_player(option[i]);
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if (!ob1) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-i] [-w] [-p] [<ID>]\n"); 
                                        if( me && !me->visible(ob1) ) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-i] [-w] [-p] [<ID>]\n");
                                        me = ob1; opt_party = 1;
                        }
        }
/*
        if (SendInterMud) {
                RWHO_Q->send_rwho_q(HostName,me, strMsg );
                write("网路讯息已送出，请稍候。\n");
                return 1; 
                }
*/
       if( opt_long && !wizardp(me)) {
                if( (int)me->query("jing") < 5 )
                        return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
                me->receive_damage("jing", 5);
        }

    str = HIG "◎" + CHINESE_MUD_NAME + HIG "◎" + HIW + ENGLISH_MUD_NAME+ NOR+"目前在线的";
    if(opt_party) if(me->query("family/family_name")) str += HIR + "(" + me->query("family/family_name") + ")" +  NOR;
                        else str += HIR + "(无门派)" + NOR;
    if ( opt_wiz )
                str += "神仙有：";
    else
        if ( opt_long ) str += "玩家有：";
                else
                        str += "总人物有：";
        str += "\n";
        str +=HIW "⊙≡"HIB"───────────────────────────────────"HIW"≡⊙\n"NOR;
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
                                        name = sprintf( HIY"%s%-10s(%-12s"HIB"│","@",
                                                list[j]->name(1),
                                                capitalize(list[j]->query("id"))+")");
                                else if(list[j]->query_temp("netdead")) 
                                        name = sprintf( HIB"%s%-10s(%-12s"HIB"│","#",
                                                list[j]->name(1),
                                                capitalize(list[j]->query("id"))+")");
                                else 
                                        name = sprintf( HIW"%s%-10s(%-12s"HIB"│"," ",
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

       str += HIW "⊙≡"HIB"─────────────────────────"HIY"金庸群侠传"HIB"─────"HIW"≡⊙\n"NOR;
        str = sprintf("%s共有 %d 位使用者连线中，系统负担：%s\n " + HIY"@"NOR + " 表示发呆中，" + HIR"#"NOR + " 表示断线中。\n", str, ppl_cnt,
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
指令格式 : who [-h] [-l] [-w] [-p] [<ID>]

这个指令可以列出所有在线上的玩家及其等级。

-h 列出帮助屏幕。
-l 选项列出较长的讯息。
-p 只列出同门的玩家。
-w 只列出线上所有的巫师。
<ID> 列出<ID>代表玩家所属门派的玩家。

"HIY"@"NOR" 表示"HIY"发呆"NOR"中，"HIB"#"NOR" 表示"HIB"断线"NOR"中。

相关指令： finger
"
    );
    return 1;
}

