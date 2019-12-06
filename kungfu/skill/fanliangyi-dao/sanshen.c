// sanshen.c ���������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void do_attack(object me,object target,int attack_time)
{
    int i;
    if (!me) return;
    me->delete_temp("perform");
    if (!living(me) || !target ) return;
    if (environment(me)!=environment(target)) return;
        for(i = 0; i < attack_time; i++)
            if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
              me->set_temp("action_msg","������");
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
            }else break;
    me->start_call_out( (: call_other, __FILE__, "del_perform", me:), 1);
   
}

int perform(object me, object target)
{
    object weapon, ob;
    string msg;
 
    if( !me->is_fighting() )
        return notify_fail("����������塹ֻ����ս����ʹ�á�\n");
    if (me->query_temp("perform"))  return notify_fail("����һ����ʽ��û���!\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if( (int)me->query("neili") < 100 )
        return notify_fail("�������������\n");
    if( (int)me->query_skill("blade") < 50 ||
        me->query_skill_mapped("blade") != "fanliangyi-dao")
        return notify_fail("��ġ������ǵ������������ң��޷�ʹ�á���������塹��\n");
    msg = HIY "$Nʹ����ɽ�ɾ�������������塹����ͻ�ر���쳣�鶯Ʈ����\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -100);
    me->start_call_out( (: call_other, __FILE__, "do_attack", me, ob,3 :), 2);
    me->set_temp("perform",1);
    call_out("del_perform",3,me);
    return 1;
}

