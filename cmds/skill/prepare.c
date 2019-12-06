// prepare.c
#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = 
([
        "finger":   "指法",
        "hand":     "手法",
        "cuff":     "拳法",
        "claw":     "爪法",
        "strike":   "掌法",
        "blade":    "刀法",
        "sword":    "剑法",
        "staff":    "杖法",
        "club":     "棍法",
        "throwing": "暗器",
        "unarmed":  "拳脚",
]);

int main(object me, string arg)
{
        mapping smap, pmap;
        string *skill, basic1, basic2, arg1, arg2, arg3;
//        int i, count;
        int i;

        seteuid(getuid());

        smap = me->query_skill_map();

        if( !mapp(smap) || sizeof(smap)==0 )
                return notify_fail(HIR"你现在没有使用任何有效特殊技能。\n"NOR);

        pmap = me->query_skill_prepare();
        if (!pmap) pmap = ([]);

        if( !arg ) 
        {
                if( !mapp(pmap) || sizeof(pmap)==0 )
                        return notify_fail(HIR"你现在没有组合任何特殊拳术技能。\n"NOR);

                skill = keys(valid_types);
                write(HIC"以下是你目前组合中的特殊拳术技能。\n"NOR);
                for (i=0; i<sizeof(skill); i++) {
                        if( !me->query_skill(skill[i]) 
                        || !pmap[skill[i]] ) continue;
                        write(  valid_types[skill[i]] + " (" + skill[i] + ")" 
                                + "   " + to_chinese(pmap[skill[i]]) + "\n");
                }
                return 1;
        }

        if( arg=="?" ) 
        {
                write(HIG"以下是可以使用特殊拳术技能的种类：\n"NOR);
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }

        if( arg=="none" ) 
        {
                if( !mapp(pmap) || sizeof(pmap)==0 )
                        return notify_fail(HIB"你现在没有组合任何特殊拳术技能。\n"NOR);

                skill = keys(pmap);
                for (i=0; i<sizeof(skill); i++) {
                        me->prepare_skill(skill[i]);
                }

                me->reset_action();
                write(WHT"取消全部技能准备。\n"NOR);
                return 1;
        }

        if ( sizeof(pmap) >= 2 ) 
                return notify_fail(HIW"你现在已经组合了两种特殊技能。\n"NOR);

        if ( sscanf(arg, "%s %s %s", arg1, arg2, arg3) >= 3)
                return notify_fail("指令格式：prepare|bei [<技能名称一>|<技能名称二>]\n");
                
        if ( sscanf(arg, "%s %s", arg1, arg2) ==2 ) 
        {
                if ( sizeof(pmap) == 1 ) 
                        return notify_fail(HIM"你已准备有一种技能了。\n"NOR);
                else
                {
                        if( !me->query_skill(arg1, 1) || !me->query_skill(arg2, 1) )
                                return notify_fail(BLU"你至少不会这两种技能其中之一。\n"NOR);

                        if( !SKILL_D(arg1)->valid_combine(arg2) )
                                return notify_fail(MAG"这两种拳术技能不能组合。\n"NOR);

                        skill = keys(valid_types);
                        for (i=0; i<sizeof(skill); i++) {
                                if( smap[skill[i]] == arg1 ) basic1 = skill[i];
                                if( smap[skill[i]] == arg2 ) basic2 = skill[i];
                        }

                        if ( !basic1 || !basic2 ) 
                                return notify_fail(YEL"这两种拳术尚未激发或目前不能准备。\n"NOR);

                        me->prepare_skill(basic1, arg1);
                        me->prepare_skill(basic2, arg2);

                        me->reset_action();
                        write(HIY"完成技能准备。\n"NOR);
                        return 1;
                }               
        }

        if ( sscanf(arg, "%s", arg1) ==1 && sizeof(pmap) <= 1 ) 
        {
                if( !me->query_skill(arg1, 1) )
                        return notify_fail(MAG"你不会这种技能。\n"NOR);

                skill = keys(pmap);

                if( sizeof(pmap) == 1 
                && !SKILL_D(arg1)->valid_combine(pmap[skill[0]]) )
                        return notify_fail(HIB"这种技能不能於你现有技能组合。\n"NOR);

                skill = keys(valid_types);
                for (i=0; i<sizeof(skill); i++) {
                        if( smap[skill[i]] == arg1 ) basic1 = skill[i];
                }

                if ( !basic1 ) 
                        return notify_fail(HIC"这种技能尚未激发或目前不能准备。\n"NOR);

                me->prepare_skill(basic1, arg1);
                me->reset_action();
                write(HIY"完成技能准备。\n"NOR);
        
                return 1;
        }
        
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : prepare|bei [<拳术技能名称>|<拳术技能名称> | none]
           prepare|bei ?

这个指令让你指定所要用的拳术技能， 需指明一种以上的相应技能名称。
如果不加参数则会显示出技能种类及你目前所使用的技能名称 ，如果加一
个"?"，则会列出所有能使用特殊拳术技能的技能种类。
 
HELP
        );
        return 1;
}
