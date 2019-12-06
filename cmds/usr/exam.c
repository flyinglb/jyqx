#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
//         object ob;
        mapping my;
 
        seteuid(getuid(me));
 
        if(!me->query("weapon"))
                return notify_fail("你还没有自制的武器。\n");
 
        my = me->query("weapon");
 
    printf(" 武器名称  ： %12s  打造时间 ： %s\n" , my["name"], my["time"]);
    printf(" 材    料  ： %12s  类    型 ： %s\n" , my["or"], my["type"]);
    printf(" 目前级别　： %d/%d\n" ,my["lv"], my["value"]);
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : exam
 
这个指令可以显示你自制的武器的详细资料。

HELP
    );
    return 1;
}

