// recover.c
//inherit SSERVER;
int exert(object me, object target)
{
    int n, q;
    if (me != target)
        return notify_fail("你只能用内功调匀自己的气息。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够。\n");
        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
    q = (int)me->query("eff_qi") - (int)me->query("qi");
    if (q < 10)
        return notify_fail("你现在气息充沛。\n");
    n = 100 * q / me->query_skill("force");
    n = 30 * n / me->query_con();
    if (n < 20)
        n = 20;
    if ((int)me->query("neili") < n) {
        q = q * (int)me->query("neili") / n;
        n = (int)me->query("neili");
    }
    me->add("neili", -n);
    me->receive_heal("qi", q);
    
        message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);
        if( me->is_fighting() ) me->start_busy(1);
        if (me->query_skill("force",1) < 500)
        me->improve_skill("force", random(8),0);
        else
       me->improve_skill("force", random(me->query_skill("force", 1)/3),0);
    return 1;
}
