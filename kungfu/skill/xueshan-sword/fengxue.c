#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object ob;
        object weapon;
        string msg;
        ob=me->query_temp("weapon");
        if( !target ) target = offensive_target(me); 

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"����"HIW"ѩ"HIC"�ؽ���"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n"); 

         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ����������������"+HIC"����"HIW"ѩ"HIC"�ؽ���"NOR+"��\n");

        if((int)me->query_skill("xueshan-sword",1) < 150)
                return notify_fail("���ѩɽ����������죬ʹ����"+HIC"����"HIW"ѩ"HIC"�ؽ���"NOR+"��\n");

        if((int)me->query("neili") < 220)
                return notify_fail("�����������ڲ����� \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        msg = HIC "$N�ؽ����裬���Ʋ��ϼӿ죬������Х��ɢ����ƬƬѩ�����磬ƮȻ������\n�γ�һ��ѩ�������У���$n�������\n";
        if(random(me->query_skill("sword",1)+me->query_skill("xueshan-sword",1)+me->query_skill("dodge",1)) > ((int)target->query_skill("dodge",1))) {
                msg +=HIG "$nֻ��������ѹ��Խ��Խ�󣬵��������������������������á�\n" NOR;
                target->start_busy( (int)me->query_skill("xueshan-sword",1) / 30);
                me->add("neili", -100);
        } else {
                msg +=HIR "����$n����������ѩ����ʱȫ���ܽ⣬һƬ��ʣ���ѳ���Χ��\n" NOR;
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

