// erase.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        int double_skill;
        int amount;

        if( !me->is_fighting() )
           return notify_fail("����֮��ֻ����ս����ʹ�á�\n");
        if( target != me ) return
           notify_fail("��ֻ����Ǭ��Ų���񹦻����Լ��Ĺ�����\n");
        if( (int)me->query("force") < 30 ) return notify_fail("�������������\n");
        if( me->query_temp("shift") ) return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = (int)me->query_skill("force");

        me->add("force", -30);
        write("������һת��������Ǭ����Ų���񹦣�����ѵ��˵Ĺ���������Ӱ���١�\n");
        //me->add_temp("apply/dodge", skill * 10);
        me->add_temp("apply/parry", skill * 10);
        me->set_temp("shift", "erase");
        //me->receive_damage("sen",10);
        double_skill = me->query_skill("shiftforce", 1);
        amount = skill * 10;
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
           amount :), double_skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
   if (me->query("shift") == "erase" )
      { me->add_temp("apply/parry", - amount);
        //me->add_temp("apply/dodge", - amount);
        me->delete_temp("shift");
        tell_object(me, "���Ǭ����Ų����������ϣ��������ջص��\n");
      }
}
 
