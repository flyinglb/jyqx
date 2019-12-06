// hitback.c

#include <ansi.h>

inherit F_CLEAN_UP;

//void remove_effect(object me, int amount);
void remove_effect(object me);

int exert(object me, object target)
{
        int skill;
        int three_skill;

        if( !me->is_fighting() )
           return notify_fail("ת��֮��ֻ����ս����ʹ�á�\n");
        if( target != me ) return
           notify_fail("��ֻ����Ǭ��Ų����ת�����Լ��Ĺ�����\n");
        if( (int)me->query("force") < 50 ) return notify_fail("�������������\n");
        if( me->query_temp("shift") ) return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("force", -50);
        //me->receive_damage("sen", 20);
        write("������һת��������Ǭ����Ų���񹦣�����ѵ��˵Ĺ���ת�ظ����Լ���\n");
        me->set_temp("shift", "hitback");
        three_skill = me->query_skill("shiftforce", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :),
           three_skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me)
{
  if (me->query_temp("shift") == "hitback")
	{
	me->delete_temp("shift");
      tell_object(me, "���Ǭ����Ų����������ϣ��������ջص��\n");
     }
}
 
