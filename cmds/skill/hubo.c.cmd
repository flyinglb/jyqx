// hubo.c
// modified by risc  in 1/1/2001
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	string msg;
	int count;

    if( me->is_busy() )
	return notify_fail("��Ķ�����û����ɣ�����ʹ�á�˫�ֻ���֮������\n");
    if (!me->query_skill("hubo",1))
       return notify_fail("�㲻�ᡸ˫�ֻ���֮������\n");
//    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//       return notify_fail("��ֻ�п��ֲ����á�˫�ֻ���֮������\n");
//    if (me->query("gender")!="����")
//       return notify_fail("�㲻��ʹ�á�˫�ֻ���֮������\n");
//    if (me->query("int")> 24)
//       return notify_fail("�㲻��ʹ�á�˫�ֻ���֮������\n");
    if( !me->is_fighting() )
        return notify_fail("��˫�ֻ���֮����ֻ����ս����ʹ�á�\n");

    if( (int)me->query("jing") < 70 ) return notify_fail("��ľ�������\n");
    if( (int)me->query("neili") < 150 )
        return notify_fail("�������������\n");

    if (me->query("hubo_busy_tag"))
        return notify_fail("������񻹲��ܼ��У�\n");

    msg = HIY "$Nƽ�ľ�������̨������ʹ����˫�ֻ���֮������˫��ͬʱ���У�\n" NOR;

    message_vision(msg, me);
    count = (40 - (int)me->query("int")) / 5 + (int)me->query_skill("hubo") / 30 ;
    if( count < 1 ) count = 1 ;
    if ( count > 6 ) count = 6 ;
    while( count-- )
    {
		object ob;

	me->clean_up_enemy();
	ob = me->select_opponent();
        if(!ob || (environment(ob) != environment(me))) 
        {
            message_vision(CYN "$NͻȻ����һ�ң��Ѳ��ܼ���˫�ֻ�����\n" NOR, me);
			break;
        }
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        if (!me->query("hubo_busy_tag")) me->set_temp("hubo_busy_tag",1);// by cmd
//        COMBAT_D->fight(me, ob) ;
    }
    remove_call_out("clean_hubo_tag");
     call_out("clean_hubo_tag",3,me);
// me->start_busy(1) by cmd
    me->receive_damage("jing", 50);
    me->add("neili", -100);
    return 1;
}

void clean_hubo_tag(object me)
{
    me->delete("hubo_busy_tag");
}
int help(object me)
{
        write(@HELP
ָ���ʽ : hubo
 
���ָ����������ڶԵ�ʱʹ��˫�ֻ���֮��,���ٳ��С�
 
HELP
    );
    return 1;
}
