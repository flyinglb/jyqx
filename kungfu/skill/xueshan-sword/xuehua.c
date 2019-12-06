
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
//        int count;
        if( !target ) target = offensive_target(me);
 
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��"HIW"ѩ������"NOR"��ֻ����ս����ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(" ��ʹ�õ���������\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("bingxue-xinfa",1) < 50 )
                return notify_fail("��ı�ѩ�ķ���Ϊ��������\n");

        if( (int)me->query_skill("sword",1) < 50 ||
            me->query_skill_mapped("sword") != "xueshan-sword" || 
            me->query_skill("xueshan-sword",1) < 50)
                return notify_fail("���ѩɽ������Ϊ�������޷�ʹ�á�ѩ����������\n");

        msg = HIY "$Nһ�����г�����һʽ"HIW"��ѩ��������"NOR+HIY"�������̳������������������ǣ�\n�ó�ѩ�����㣬����һ�����ǰ��Ʈ��ȥ��\n" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", 200);
        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -100);
        me->start_busy(2+random(1));

        me->add_temp("apply/attack", -200);
        if(!ob->is_fighting(me)) ob->fight_ob(me);
        return 1;
}

