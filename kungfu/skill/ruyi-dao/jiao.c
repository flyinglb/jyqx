//made by long
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	object my_w,ob_w;
        my_w = me->query_temp("weapon");

//modified by wind
        if( !target ) target = offensive_target(me);
        if( !target )
                 return notify_fail("��Ҫ��˭ʹ�ý��־�?\n");
	ob_w = target->query_temp("weapon");


        if( !(me->is_fighting() ))
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á����־�����\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ��ƣ���мܣ��ӽ������ɡ�\n");
//modified by wind,no change
      if( (int)me->query_skill("ruyi-dao", 1) < 120 )
                return notify_fail("������⵶��������죬����ʹ�á��¡��־���\n");

        msg = CYN "$N���һ����չ�����⵶�����¡��־�����������������ͼ����$n�ı�����\n";
        me->start_busy(2);

        if (target->query_temp("weapon") ||
            target->query_temp("secondary_weapon")) {

        if( random(me->query("combat_exp")) >
                     (int)target->query("combat_exp")/2 ) {
	if( ob_w->weight() > 2 * random(my_w->weight())){
	msg += "���$P���е�"+ob_w->query("name")+"������һ���ѳֲ�ס���ֶ���\n"NOR;
		ob_w->unequip();
		ob_w->move(environment(target));
                 target->reset_action();
                target->start_busy( (int)me->query_skill("ruyi-dao",1) / 50 );
         }
                msg += "���$p���еı��б�$P��ǿ��һ�����˸����飡\n" NOR;
		ob_w->unequip();
		ob_w->move(environment(target));
		ob_w->set("name", ob_w->query("name")+"����");
		ob_w->set("value", 0);
		ob_w->set("weapon_prop", 0);
                 target->reset_action();
                target->start_busy( (int)me->query_skill("ruyi-dao",1) / 100 );
        } else {
                msg += "����$pͨ��������мܣ�$P�ļ�ıû�еóѡ�\n" NOR;

        //added by wind, not change
          me->start_busy( 5+random(5) );        
        }
        message_vision(msg, me, target);
        return 1;
        }
        return notify_fail(target->name() + "Ŀǰ�ǿ��֣������ʲô��\n");
}
