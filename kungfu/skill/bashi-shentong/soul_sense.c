// soul_sense.c ��ʶ��ͨ
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
    int skill;

    if( me->query_temp("apply/astral_vision") )
   return notify_fail("���Ѿ�ʩչ����ʶ�ˡ�\n");

    if( (int)me->query("jingli") < 30 )
   return notify_fail("��ľ���������\n");

    skill = me->query_skill("magic");

    me->add("jingli", - 30);
    me->receive_damage("jing", 5);

    message_vision(
   HIC "$N΢һ����ʩչ����ʶ��֮����\n" NOR, me);
    tell_room(environment(me),HIY+ me->query("name")+"˫�ֺ�Ϊ��ָ����ǰ����
������˫�۾���Ϊ���ɫ���·��ܶ���һ�У�\n"NOR);
    me->add_temp("apply/astral_vision", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);
    if( me->is_fighting() ) me->start_busy(1);

    return 1;
}

void remove_effect(object me)
{
    me->add_temp("apply/astral_vision", -1);
    tell_object(me, HIC"�����ʶʧЧ�ˡ�\n"NOR);
}

