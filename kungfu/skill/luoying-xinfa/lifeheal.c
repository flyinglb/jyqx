// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
    if ((!target)||target->query("id")==me->query("id"))
   return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

    if( me->is_fighting() || target->is_fighting())
   return notify_fail("ս�����޷��˹����ˣ�\n");

    if( (int)me->query("max_neili") < 300 )
   return notify_fail("���������Ϊ������\n");

    if( (int)me->query("neili") < 100)
   return notify_fail("�������������\n");

    if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
   return notify_fail( target->name() +
      "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

    message_vision(
   HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
   "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
   me, target );

    target->receive_curing("qi", 10 + (int)me->query_skill("force")/2 );
    target->add("qi", 10 + (int)me->query_skill("force")/3 );
    target->receive_curing("jing", 10 + (int)me->query_skill("force")/2 );      
    target->add("jing", 10 + (int)me->query_skill("force")/3 );
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    if( (int)target->query("jing") > (int)target->query("eff_jing") ) target->set("jing", (int)target->query("eff_jing"));

    me->add("neili", -100);

    return 1;
}

// powerup.c

