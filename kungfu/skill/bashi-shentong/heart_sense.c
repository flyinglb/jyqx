// heart_sense.c ��ʶ��ͨ
// Modified by Venus Oct.1997

#include <ansi.h>

//inherit SSERVER;

int conjure(object me, object target)
{
    if( !target || !target->is_character() )
      return notify_fail("��Ҫ��˭ʹ����ʶ��ͨ��\n");
    if( target->is_corpse() )
      return notify_fail("�������ˣ�ֻ�л��˲��ܾ��ѡ�\n");

    if( (int)me->query("jingli") < 50 ) return notify_fail("��ľ���������\n");
       me->add("jingli", -50);
       me->receive_damage("jing", 30);
       message_vision( HIY "$Nһ�ַ���$n��������ϣ�һ������$n�����ģ������۾�������� ...\n" NOR,me, target );
    if( random(me->query("max_jingli")) > 100 )
       target->revive();
    else
       me->unconcious();
    if( me->is_fighting() )
       me->start_busy(3);
    return 1;
}

