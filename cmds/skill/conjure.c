// conjure.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string spells, spl, trg;
        object target;

        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( 你上一个动作还没有完成，不能施展神通。)\n");

        if( environment(me)->query("no_magic") )
                return notify_fail("这里无法使用神通。\n");

        if( !arg || arg == "" ) return notify_fail("指令格式：conjure <神通> [on <目标>]\n");
        if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
                target = present(trg, environment(me));
      if((spl=="spattack" || spl=="mpattack") && target->query("age")<16)
         return notify_fail("饶了人家吧，没看到人家还这么小……\n");
                if( !target ) target = present(trg, me);
                if( !target ) return notify_fail("这里没有 " + trg + "。\n");
                spl = arg;
                target = 0;
        }

        if( !spl ) spl = arg;
        spl = replace_string( spl, " ", "_");

        if( stringp(spells = me->query_skill_mapped("magic")) )
                return (int)SKILL_D(spells)->conjure_magic(me, spl, target);

        return notify_fail("你请先用 enable 指令选择你要使用的神通系。\n");
}

int help (object me)
{
        write(@HELP
指令格式：conjure <法术名称> [on <对象>]

施    法：你必需要指定<法术名称>，<对象>则可有可无。
在你使用某一个法术之前，你必须先用 enable|jifa 指令来指定你要使用的法术系。

HELP);
        return 1;
}

