// wubao_poison.c 五宝花蜜酒毒

#include <ansi.h>

int update_condition(object me, int duration)
{

	if(me->query("neili") > 1500) {
	        me->add("neili",-150);
	        me->receive_damage("qi", 10);
	
	        tell_object(me, 
	        HIY "你忽的觉得胸口一阵烦恶，立刻强自运气忍住。\n"
	        + "似乎是中了什么毒。\n" NOR );
	
	        tell_room(environment(me), 
	        HIY + me->query("name")+"脸上一阵发青，似乎十分难受。\n"NOR, me);
	
	        me->apply_condition("wubao_poison", duration - 20);
	} else if(me->query("neili") > 1000) {
	        me->add("neili",-100);
	        me->receive_damage("qi", 15);
	
	        tell_object(me, 
	        HIY "你忽的觉得胸口一阵烦恶，立刻强自运气，好一阵才忍住。\n"
	        + "似乎是中了什么毒。\n" NOR );
	
	        tell_room(environment(me), 
	        HIY + me->query("name")+"脸上一阵发青，眉头深锁，似乎十分难受。\n"NOR, me);
	
	        me->apply_condition("wubao_poison", duration - 10);
        } else {
                me->receive_wound("jing", 5);
                me->receive_damage("qi", 5);

	        tell_object(me, 
	        HIY "你忽的觉得胸口一阵烦恶，一下忍不住“哇”的一声吐了出来。\n"
	        + "看来是中了五宝花蜜酒的毒。\n" NOR );

	        tell_room(environment(me), 
	        HIY + me->query("name")+"脸上一阵发青，双手包着肚子“哇”的一声吐了起来。\n"NOR, me);

	        if( !me->is_fighting() ) me->start_busy(1);
	        me->apply_condition("wubao_poison", duration - 2);
        }
        
	if( duration < 1 ) {
	        tell_object(me, HIY "渐渐的你觉得胸口的烦气化尽，似乎感觉好多了。\n"NOR );
	        return 0;
	}
	return 1;
}
