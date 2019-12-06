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
private string cuptime();

mixed main(object me, string arg)
{
        object *list, ob1;
        string str;
        int option, i;
        
        if(arg) {
                switch(arg) {
                        case "-h": return help();
                        case "-l": strMsg="-l",option = 1; break;
                        case "-w": strMsg="-w",option = 2; break;
                        case "-p": strMsg="-p",option = 3; break;
                        default: 
                                ob1 = present(arg, environment(me));
                                if (!ob1) ob1 = find_player(arg);
                                if (!ob1) ob1 = find_living(arg);
                                if (!ob1) return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]\n"); 
                                me = ob1; option = 4;
                }
        }
                
        if( !option && !wizardp(me)) {
                if( (int)me->query("jing") < 60 )
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("jing", 50);
        }
        
        str = HIG "��" + MUD_NAME + HIG "��" +  NOR+"Ŀǰ���ߵ�";
        
        if(option>1) str += "��ʦ�У�";
        else str += "����У�";
        
        if(option>2) {
                if(me->query("family/family_name"))
                        str += HIR + "(" + me->query("family/family_name") + ")" +  NOR;
                else str += HIR + "(������)" + NOR;
                str += "�����У�";
        }
        str += "\n";
        str +=HIW"����������������������������������������������������������������������\n"NOR;
                
        switch(arg) {
                case "-l": strMsg="-l",option = 1; break;
                case "-w": strMsg="-w",option = 2; break;
                case "-p": strMsg="-p",option = 3; break;
        }
        
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

