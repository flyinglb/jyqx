// wubao_poison.c �屦���۾ƶ�

#include <ansi.h>

int update_condition(object me, int duration)
{

	if(me->query("neili") > 1500) {
	        me->add("neili",-150);
	        me->receive_damage("qi", 10);
	
	        tell_object(me, 
	        HIY "����ľ����ؿ�һ�󷳶�����ǿ��������ס��\n"
	        + "�ƺ�������ʲô����\n" NOR );
	
	        tell_room(environment(me), 
	        HIY + me->query("name")+"����һ���࣬�ƺ�ʮ�����ܡ�\n"NOR, me);
	
	        me->apply_condition("wubao_poison", duration - 20);
	} else if(me->query("neili") > 1000) {
	        me->add("neili",-100);
	        me->receive_damage("qi", 15);
	
	        tell_object(me, 
	        HIY "����ľ����ؿ�һ�󷳶�����ǿ����������һ�����ס��\n"
	        + "�ƺ�������ʲô����\n" NOR );
	
	        tell_room(environment(me), 
	        HIY + me->query("name")+"����һ���࣬üͷ�������ƺ�ʮ�����ܡ�\n"NOR, me);
	
	        me->apply_condition("wubao_poison", duration - 10);
        } else {
                me->receive_wound("jing", 5);
                me->receive_damage("qi", 5);

	        tell_object(me, 
	        HIY "����ľ����ؿ�һ�󷳶�һ���̲�ס���ۡ���һ�����˳�����\n"
	        + "�����������屦���۾ƵĶ���\n" NOR );

	        tell_room(environment(me), 
	        HIY + me->query("name")+"����һ���࣬˫�ְ��Ŷ��ӡ��ۡ���һ������������\n"NOR, me);

	        if( !me->is_fighting() ) me->start_busy(1);
	        me->apply_condition("wubao_poison", duration - 2);
        }
        
	if( duration < 1 ) {
	        tell_object(me, HIY "������������ؿڵķ����������ƺ��о��ö��ˡ�\n"NOR );
	        return 0;
	}
	return 1;
}
