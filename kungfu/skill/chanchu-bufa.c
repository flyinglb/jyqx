// chanchu_bufa.c 蟾蜍步法
inherit SKILL;
string *dodge_msg = ({
    "只见$n一招「"+RED+"蟾飞九天"+NOR+"」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
    "但是$n一个使出「"+WHT+"蛙鸣震天"+NOR+"」，身形飘忽，轻轻一纵，早已避开。\n",
     "$n一招「"+CYN+"蛙入稻田"+NOR+"」，身行随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
    "可是$n一个「"+YEL+"蟾蜍扑虫"+NOR+"」，侧身一让，$N这一招扑了个空。\n",
    "却见$n「"+RED+"蟾翻白肚"+NOR+"」，足不点地，往旁窜开数尺，躲了开去。\n",
    "$n身形一招「"+GRN+"金蟾归月"+NOR+"」，身形微晃，有惊无险地避开了$N这一招。\n"
});
int valid_enable(string usage) { return (usage == "dodge");  }
int valid_learn(object me)
{
    if (me->query_skill("dodge",1) <= me->query_skill("chanchu-bufa",1) )
        return notify_fail("你的基本轻功基础不够，无法领会更高深的蟾蜍步法。\n");
    else    return 1;
}
int practice_level(){   return 60;  }
string query_dodge_msg(string limb,object me)
{
    me->set_temp("apply/dodge",me->query_skill("chanchu-bufa")/3);
    return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 45 )
        return notify_fail("你的体力太差了，不能练蟾蜍步法。\n");
    me->receive_damage("qi", 35);
    return 1;
}
