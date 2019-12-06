// powerup.c ��ľ�񹦼���
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("��ֻ���ÿ�ľ���������Լ���ս������\n");
    if( (int)me->query("neili") < 100  ) 
        return notify_fail("�������������\n");
    if( (int)me->query_temp("powerup") ) 
        return notify_fail("���Ѿ����˹����ˡ�\n");
    skill = me->query_skill("kumu-shengong",1);
    if (skill<60) return notify_fail("��Ŀ�ľ�񹦻�������졣\n");
    me->add("neili", -100);
    me->receive_damage("qi", 0);
    message_vision( BOLD "$N΢һ���������ľ�񹦣���ɫ��Ȼ��Ʊ�ò�����\n" NOR, me);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill);
    me->set_temp("powerup", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/2);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
    if (!me)    return;
   if ( (int)me->query_temp("powerup") ) {
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, BOLD"��Ŀ�ľ��������ϣ��������ջص��\n"NOR);
    }
}
