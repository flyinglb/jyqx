// zhen.c ̫��ȭ�������־�
// snowman
#include <ansi.h>

inherit F_SSERVER;
string *taiji_msg = ({"��ȸβ","����","��������","�׺�����","§ϥ����","��������","��̽��",
"����ʽ","������","�𼦶���","��Ů����","��������","�乭�仢","������ɽ",});

int perform(object me, object target)
{
        int damage, force;
        string msg, *limbs;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if(!me->query_temp("taiji"))
//                return notify_fail("̫��ȭҪּ�����ɷ��ɣ���û�����á�̫�������������ʹ�á������־���\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������������ǿ��ʹ�á������Ƿ��Ӳ������������ģ�\n");
        if( (int)me->query("jing", 1) < 100 )
                return notify_fail("�����ھ���������ǿ��ʹ�á������Ƿ��Ӳ������������ģ�\n");                     
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     
                
        limbs = target->query("limbs");
        msg = CYN "\n$Nʹһ��̫��ȭ��"+taiji_msg[random(sizeof(taiji_msg))]+"�����ҽ�ʵ������飬����"RED"������"CYN"�־���ճ��ճ�棬�����Ѵ�ס$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
        
        force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("unarmed")) > target->query_skill("unarmed")/2){
                me->start_busy(2);
                if(!target->is_busy()) target->start_busy(random(2));
                
                damage = (int)me->query_skill("force");                
                if(me->query("neili") > target->query("neili")*2) damage *= 2;
                else if(me->query("neili") > target->query("neili")*3/2) damage += random(damage);
                else if(me->query("neili")*2 < target->query("neili")) damage /= 2;
                else if(me->query("neili") < target->query("neili")) damage -= random(damage);
                else damage = damage/2 + random(damage);
                if(damage> 1000) damage = 1000; 
                target->receive_damage("jing", damage/4);
                target->receive_damage("qi", damage/4);
                me->add("neili", -(damage/4));
                me->add("jing", -50);
                msg += HIR"����$P�ᾢ������$p����ôһ�������ӱ��Լ��ľ������ò���������ǰһ�壬���������\n"NOR;       
                } 
        else{
                me->start_busy(3);
                me->add("jing", -25);
                me->add("neili", -150);
                msg += HIY"$p�����龰��һ�����棬��æ�ջ��Լ��ľ�����������ã�\n"NOR;
             }
        message_vision(msg, me, target);
        return 1;
}

