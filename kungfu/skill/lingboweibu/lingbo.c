// lingbo.c  洛神凌波

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("你一个人跳甚么？\n");

        if( me->query("gender") == "无性")
                return notify_fail(HIY "一个公公，满场乱跳，羞也不羞？\n" NOR);

        if((int)me->query_skill("beiming-shengong",1) < 100)
                return notify_fail(HIY "你的北冥神功修为不够。\n" NOR);

        if((int)me->query_skill("lingboweibu",1) < 100)
                return notify_fail(HIY "你的凌波微步不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if( me->query("gender") == "男性")
               {msg = HIC 
"$N提起真气，依照先天伏羲六十四卦，不理$n如何出招，自顾自的将
凌波微步由头到尾迅速无比的走了一次。只见$N意态飘逸，影子乱飞，
$n却是一点皮毛也沾不上。$N真个将逍遥二字发挥得淋漓尽至。\n" NOR;}
        else   {msg = HIG 
"$N提起真气，依照先天伏羲六十四卦，不理$n如何出招，自顾自的将
凌波微步由头到尾迅速无比的走了一次。$N仿如洛神再生，微步凌波，
$n却是一点皮毛也沾不上。$N真个将逍遥二字发挥得淋漓尽至。\n" NOR;}

        if( me->query("combat_exp")*random(2) > (int)target->query("combat_exp")/ 4 ) {
                msg += HIW "结果$p被$P围着转得头晕眼花！\n" NOR;
                target->start_busy( (int)me->query_skill("lingboweibu",1) / 30);
                me->add("neili", -100);
                me->start_busy(1);
        } else {
                msg += HIG "$p只是勉强的逃了开去。\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}
