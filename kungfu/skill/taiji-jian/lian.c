// lian.c ̫�������������־�
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void do_attack(object me,object target,object weapon,int attack_time)
{
    int i;
    if (!me) return;
    me->delete_temp("perform");
    if (!living(me) || !target ) return;
    if (weapon == me->query_temp("secondary_weapon") )
    me->set_temp("secondly_weapon",1);
    if (!weapon->query("equipped")){ me->start_busy(1); return; }
    if (environment(me)!=environment(target)) return;
        for(i = 0; i < attack_time; i++)
            if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
              me->set_temp("action_msg","������");
// �ϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��ģ�
                if (!weapon->query("equipped")){ me->start_busy(1); return; }
        if (me->query_skill_mapped("sword")!="taiji-jian") {me->start_busy(1); return; }
              COMBAT_D->do_attack(me, target, weapon, 0);
            }else break;
    me->delete_temp("secondly_weapon");
    if (i) message_vision(CYN " ���$p��$P���˸����ֲ�����\n" NOR, me, target);
}

int perform(object me, object target)
{
    object weapon;
    string msg;
    int attack_time;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if( (int)me->query_skill("taiji-jian", 1) < 60 )
        return notify_fail("���̫������������죬����ʹ�á������־���\n");
    if (!me->visible(target))    return notify_fail("�㿴����"+target->name()+"��\n");
    if (me->query_temp("perform"))  return notify_fail("����һ����ʽ��û���!\n");
    if ( me->query("neili")<100 )   return notify_fail("�����������!\n");
        msg = HIY "$Nʹ��̫�������������־�����ʽ��Ȼ��졣\n" NOR;
    if( !living(target) || random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        attack_time = (int)me->query_skill("taiji-jian", 1) / 55;
        if(attack_time < 1)
            attack_time = 1;
    me->start_call_out( (: call_other, __FILE__, "do_attack", me, target,weapon,attack_time :), 2);
    if (me->query("neili")<150)
        me->set("neili",0);
    else
        me->add("neili", -150);
    me->set_temp("perform",1);
    }
    else
    {
        msg += HIY  "����$p"+ HIY +"������$P����ͼ����û���ϵ���\n" NOR;
        me->start_busy(1);
    }
    message_vision(msg, me, target);
    return 1;
}

