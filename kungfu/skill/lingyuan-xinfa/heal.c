// heal.c
// Modified by Venus Oct.1997

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("ս�����˹����ˣ�������\n");

    if ((int)me->query_skill("lingyuan-xinfa", 1) < 10)
   return notify_fail("�����Ԫ�ķ���Ϊ��������\n");
    if( (int)me->query("neili") < 50 )
   return notify_fail("�������������\n");

    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 5 )
   return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    write( HIY "��ȫ����ɣ�������������Ԫ�ķ���ʼ���ˡ�\n" NOR);
    message("vision",
   HIY + me->name() + "�����˹����ˣ�ͷ���������ƣ�������³�һ����
������ɫ�ѻָ�������\n" NOR,
   environment(me), me);
    me->receive_curing("qi", 60 + (int)me->query_skill("force")/2 );
    me->receive_curing("jing", 40 + (int)me->query_skill("force")/2 );
    if( (int)me->query("qi") > (int)me->query("eff_qi") )
    me->set("qi", (int)me->query("eff_qi"));
    if( (int)me->query("jing")>(int)me->query("eff_jing") )
    me->set("jing", (int)me->query("eff_qi"));
    me->add("neili", -50);

    return 1;
}
