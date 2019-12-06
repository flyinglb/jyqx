// wushuang.c ��ɽ���� ��˫�޶�
#include <ansi.h>
// inherit F_CLEAN_UP;
void remove_effect(object me, int a_amount, int d_amount);
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int skill;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");
    if( (int)me->query_skill("huashan-jianfa", 1) < 40 )
        return notify_fail("��Ļ�ɽ����������죬����ʹ�á���˫�޶ԡ���\n");
    
    if( (int)me->query("neili") < 300  ) 
        return notify_fail("�������������\n");
    if( (int)me->query_temp("hsj_wu") ) 
        return notify_fail("���Ѿ����˹����ˡ�\n");
    msg = YEL"$N˫������" + weapon->name() + "����â������һʽ����˫�޶ԡ���Ԧ�����Ҿ��׵���$p��̣�\n"NOR;
    message_vision(msg, me, target);
    skill = (int)me->query_skill("huashan-jianfa",1);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", -skill/4);
    me->set_temp("hsj_wu", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), 2);
    me->add("neili", -100);
    return 1;
}
void remove_effect(object me, int a_amount, int d_amount)
{
     if (!me) return;
    me->add_temp("apply/attack", - a_amount);
    me->add_temp("apply/dodge", d_amount);
    me->delete_temp("hsj_wu");
}
