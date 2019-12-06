// heal.c
#include <ansi.h>
int heal_myself(object me)
{
    string force_skill=me->query_skill_mapped("force");
    
    if (!stringp(force_skill))
        return notify_fail("����ѧ���ڹ���û������ܡ�\n");
    if( me->is_fighting() )
        return notify_fail("ս�����˹����ˣ�������\n");
    if ((int)me->query_skill(force_skill, 1) < 50)
        return notify_fail("���"+to_chinese(force_skill)+"��Ϊ��������\n");
    if( (int)me->query("neili") < me->query("max_qi")/5 )
        return notify_fail("�������������\n");
    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
        return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
    if( (int)me->query("eff_qi") == (int)me->query("max_qi")  )
        return notify_fail("�����ڲ���Ҫ�˹����ˣ�\n");
    write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
    message("vision",
        HIW + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
        environment(me), me);
    me->receive_curing("qi", me->query("max_qi")/10 + (int)me->query_skill("force")/5 );
    me->add("neili", -me->query("max_qi")/5);
    me->set("jiali", 0);
        me->start_busy(1);
        me->improve_skill(force_skill, random(me->query_skill(force_skill, 1)),0);
    return 1;
}
int heal_target(object me,object target)
{
    string force_skill=me->query_skill_mapped("force");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

    if (!stringp(force_skill)) return notify_fail("����ѧ���ڹ���û������ܡ�\n");
    if( me->is_fighting() || target->is_fighting())
        return notify_fail("ս�����޷��˹����ˣ�\n");
    if( (int)me->query("max_neili") < 300 )
        return notify_fail("���������Ϊ������\n");
    if( (int)me->query("neili") < me->query("max_qi")/3 )
        return notify_fail("�������������\n");
    if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
        return notify_fail( target->name() +
            "�Ѿ����˹��أ����ܲ�����������𵴣�\n");
    if( (int)target->query("eff_qi") == (int)target->query("max_qi")  )
        return notify_fail(target->name()+"���ڲ���Ҫ���ˣ�\n");
    message_vision( HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
        "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
        me, target );
    target->receive_curing("qi", target->query("max_qi")/10 + (int)me->query_skill("force")/3 );
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    me->add("neili", -me->query("max_qi")/3);
    me->set("jiali", 0);
    target->set("jiali", 0);
    me->start_busy(5);
    target->start_busy(5);
    me->improve_skill(force_skill, random(me->query_skill(force_skill, 1)),0);
    return 1;
}
int exert(object me, object target)
{
    if( !target ||  target == me)
        return heal_myself(me);
    else
        return heal_target(me,target);
}
