// respirate.c

#include <skill.h>


private int respirate_cost;
int respirating(object me);
int halt_respirate(object me);

int main(object me, string arg)
{
        object where = environment(me);

        seteuid(getuid());

        if ((int)me->query("age") < 30)
                return notify_fail("你现在还年轻，以后再练吧！\n");

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

        if (me->is_busy() || me->query_temp("pending/respirate"))
                return notify_fail("你现在正忙着呢！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中吐纳，好象只有神仙才能做到。\n");

        if( !arg || !sscanf(arg, "%d", respirate_cost))
                return notify_fail("你要花多少精修行？\n");

        if (respirate_cost <= 0)
                return notify_fail("你不是神仙！\n");

        if( (int)me->query("jing") < respirate_cost )
                return notify_fail("你现在精不足，无法修行精力！\n");

        if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
                return notify_fail("你现在身体状况太差了，无法集中精神！\n");

        write("你闭上眼睛开始打坐。\n");
        me->set_temp("pending/respirate", 1);
        me->set_temp("respirate_cost", respirate_cost);
        message_vision("$N盘膝坐下，开始吐纳炼精。\n", me);
        me->start_busy((: respirating :), (: halt_respirate :));
        return 1;
}
int respirating(object me)
{
         int jingli_gain;
        int respirate_cost = (int)me->query_temp("respirate_cost");
        mapping fam;

	if( ((fam = me->query("family")) && fam["family_name"] == "大理段家" && me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("buddhism",1) / 6;
	else if( ((fam = me->query("family")) && fam["family_name"] == "少林派" && me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("buddhism",1) / 6;
	else if( ((fam = me->query("family")) && fam["family_name"] == "峨嵋派"&& me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("buddhism",1) / 6;
	else if( ((fam = me->query("family")) && fam["family_name"] == "雪山派"&& me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("lamaism",1) / 6;
	else  jingli_gain = 1 + (int)me->query_skill("taoism",1) / 5;


        if (respirate_cost < jingli_gain)
                jingli_gain = respirate_cost;

        me->add("jingli", jingli_gain);
        me->set_temp("respirate_cost", respirate_cost -= jingli_gain);
        me->add("jing",-jingli_gain);

        if (respirate_cost > 0)
                return 1;

        me->set_temp("pending/respirate", 0);
        respirate_cost = 0;
        message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
        if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
                return 0;
        else {
                  if ((int)me->query("max_jingli") > (int)me->query_skill("taoism",1) * 10
                        && (int)me->query("max_jingli") > (int)me->query_skill("buddhism",1) * 10
                        && (int)me->query("max_jingli") > (int)me->query_skill("lamaism",1) * 10)
//                      && (int)me->query("max_jingli") > (int)me->query_skill("mizong-xinfa",1) * 10)

                {
                        write("你的精力修为似乎已经达到了瓶颈。\n");
                        me->set("jingli", (int)me->query("max_jingli"));
                        return 0;
                }
                else
                {
                        me->add("max_jingli", 1);
                        me->set("jingli", (int)me->query("max_jingli"));
                        write("你的精力增加了！！\n");
                        return 0;
                }
        }
}

int halt_respirate(object me)
{
        respirate_cost = 0;
        if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
                me->set("jingli", (int)me->query("max_jingli") * 2);
        me->set_temp("pending/respirate", 0);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : respirate|tuna [<耗费「精」的量>]

打坐修行，利用「炼精化气，炼气化神，炼神还虚」的方法将你的精
转变成精力。

See also: exercise
HELP
        );
        return 1;
}
