// lingbo.c  �����貨

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��һ��������ô��\n");

        if( me->query("gender") == "����")
                return notify_fail(HIY "һ��������������������Ҳ���ߣ�\n" NOR);

        if((int)me->query_skill("beiming-shengong",1) < 100)
                return notify_fail(HIY "��ı�ڤ����Ϊ������\n" NOR);

        if((int)me->query_skill("lingboweibu",1) < 100)
                return notify_fail(HIY "����貨΢������������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if( me->query("gender") == "����")
               {msg = HIC 
"$N�����������������������ʮ���ԣ�����$n��γ��У��Թ��ԵĽ�
�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�ֻ��$N��̬Ʈ�ݣ�Ӱ���ҷɣ�
$nȴ��һ��ƤëҲմ���ϡ�$N�������ң���ַ��ӵ����쾡����\n" NOR;}
        else   {msg = HIG 
"$N�����������������������ʮ���ԣ�����$n��γ��У��Թ��ԵĽ�
�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�$N��������������΢���貨��
$nȴ��һ��ƤëҲմ���ϡ�$N�������ң���ַ��ӵ����쾡����\n" NOR;}

        if( me->query("combat_exp")*random(2) > (int)target->query("combat_exp")/ 4 ) {
                msg += HIW "���$p��$PΧ��ת��ͷ���ۻ���\n" NOR;
                target->start_busy( (int)me->query_skill("lingboweibu",1) / 30);
                me->add("neili", -100);
                me->start_busy(1);
        } else {
                msg += HIG "$pֻ����ǿ�����˿�ȥ��\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}
