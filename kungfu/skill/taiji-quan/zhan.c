// zhen.c ̫��ȭ��ճ���־�
// snowman
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("��ճ���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if(!me->query_temp("taiji"))
//                return notify_fail("̫��ȭ��Ҫ���ڽ�չδչ����û�����á�̫�������������ʹ�á�ճ���־���\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������������ǿ��ʹ�á�ճ���Ƿ��Ӳ������������ģ�\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     
        if( target->is_busy())
                return notify_fail("�Է����Թ˲�Ͼ�أ��㲻æʹ�á�ճ���־���\n");   
                
        msg = CYN "\n$Nһ��һʽ�ڽڹᴮ���糤����ӣ�"RED"��ճ��"CYN"��$n���ϣ�һ��ԲȦ����һ��ԲȦ��
��Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ���������಻�ϣ����ϲ�����\n"NOR;
        
        if(random(me->query("combat_exp")) > target->query("combat_exp")/2){
                damage = (int)me->query_skill("taiji-quan", 1)/20; 
                damage = 2+random(damage);
                if(damage > 7) damage = 7; 
                target->start_busy(damage);
                me->add("neili", -(damage*40));
                me->add("jing", -50);
                msg += HIR"����Ȧ��Ȧ��ʱ���׵�$p����ײײ�������������㲻�ȣ������оƻ��ԣ�\n"NOR;       
                } 
        else{
                me->start_busy(3);
                me->add("jing", -25);
                me->add("neili", -150);
                msg += HIY"$pֻ����$P̫��ȭ����֮�£��޿ɵ�����ֻ��ֻ���˾����㣬ƮȻ������\n"NOR;
             }
        message_vision(msg, me, target);
        return 1;
}

