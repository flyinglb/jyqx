// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if( (int)me->query("neili") - (int)me->query("max_neili") < 50 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return 
notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + 
"�������˹����ˣ�����һ���һ��ף����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" 
NOR,
                environment(me), me);

        me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
        me->add("neili", -50);
        me->set("force_factor", 0);
	me->start_busy(2);
        return 1;
}
 

