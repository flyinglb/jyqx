// transfer.c

#include <ansi.h>

int exert(object me, object target)
{
        int force;
		int skl,vaild;
        
        if( !target || target==me || !living(target) )
                return notify_fail("��Ҫ����������˭��\n");

        if( (string)me->query_skill_mapped("force") != target->query_skill_mapped("force") )
                return notify_fail(target->name() + "��ʹ�õ��ڹ����㲻ͬ��\n");

        if( (int)me->query("neili") <= (int)me->query("max_neili") )
                return notify_fail("����������㡣\n");

        force = me->query("neili") - me->query("max_neili");

        if( force/2 < 1 ) return notify_fail("����������㡣\n");
        me->add("neili", - force / 2 );
        message_vision("$N����������$n���ģ������������������͹�ȥ��\n", me, target);
                skl=target->query_skill("bahuang-gong",1)/2;
		vaild=skl*target->query("max_neili");
        if( random(force/3) > (int)me->query_skill("force"))
                return notify_fail("��ʧ���ˡ�\n");
		if ( target->query("neili") > vaild ){
              tell_object(target, HIR "�����һ������ͻȻ�ӵ���ӿ������������һ����ģ��۵��³�һ����Ѫ��\n" NOR);
              message_vision("$N��$p������һ����ǰһ�ڣ��������ɳ�����\n", me, target);
		 	  target->receive_wound( "qi", skl*5 ,me);
              me->receive_wound( "qi", target->query("max_neili")/30 ,target);
			  return 1;
        }
        target->add("neili", force/3);
        me->improve_skill("bahuang-gong", random(me->query_skill("bahuang-gong", 1)/10),0);
        tell_object(target, HIY "�����һ��������" + me->name() + "�����ƴ��˹�����\n" NOR);
        return 1;
}
 
