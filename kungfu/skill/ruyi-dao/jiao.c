//made by long
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	object my_w,ob_w;
        my_w = me->query_temp("weapon");

//modified by wind
        if( !target ) target = offensive_target(me);
        if( !target )
                 return notify_fail("你要对谁使用铰字决?\n");
	ob_w = target->query_temp("weapon");


        if( !(me->is_fighting() ))
                return notify_fail("你只能对战斗中的对手使用「铰字诀」。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正疲于招架，加紧攻击吧。\n");
//modified by wind,no change
      if( (int)me->query_skill("ruyi-dao", 1) < 120 )
                return notify_fail("你的如意刀法不够娴熟，不能使用「铰」字诀。\n");

        msg = CYN "$N大喝一声，展开如意刀法「铰」字诀，连递数个急招企图铰碎$n的兵器。\n";
        me->start_busy(2);

        if (target->query_temp("weapon") ||
            target->query_temp("secondary_weapon")) {

        if( random(me->query("combat_exp")) >
                     (int)target->query("combat_exp")/2 ) {
	if( ob_w->weight() > 2 * random(my_w->weight())){
	msg += "结果$P手中的"+ob_w->query("name")+"被兵器一搅把持不住脱手而飞\n"NOR;
		ob_w->unequip();
		ob_w->move(environment(target));
                 target->reset_action();
                target->start_busy( (int)me->query_skill("ruyi-dao",1) / 50 );
         }
                msg += "结果$p手中的兵刃被$P的强力一击铰了个粉碎！\n" NOR;
		ob_w->unequip();
		ob_w->move(environment(target));
		ob_w->set("name", ob_w->query("name")+"断了");
		ob_w->set("value", 0);
		ob_w->set("weapon_prop", 0);
                 target->reset_action();
                target->start_busy( (int)me->query_skill("ruyi-dao",1) / 100 );
        } else {
                msg += "可是$p通过巧妙的招架，$P的计谋没有得逞。\n" NOR;

        //added by wind, not change
          me->start_busy( 5+random(5) );        
        }
        message_vision(msg, me, target);
        return 1;
        }
        return notify_fail(target->name() + "目前是空手，你想铰什么？\n");
}
