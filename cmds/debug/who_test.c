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
                                if (!ob1) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-w] [-p] [<ID>]\n"); 
                                me = ob1; option = 4;
                }
        }
                
        if( !option && !wizardp(me)) {
                if( (int)me->query("jing") < 60 )
                        return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
                me->receive_damage("jing", 50);
        }
        
        str = HIG "◎" + MUD_NAME + HIG "◎" +  NOR+"目前在线的";
        
        if(option>1) str += "巫师有：";
        else str += "玩家有：";
        
        if(option>2) {
                if(me->query("family/family_name"))
                        str += HIR + "(" + me->query("family/family_name") + ")" +  NOR;
                else str += HIR + "(无门派)" + NOR;
                str += "人物有：";
        }
        str += "\n";
        str +=HIW"───────────────────────────────────\n"NOR;
                
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

