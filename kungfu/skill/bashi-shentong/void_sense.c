// void_sense.c ��ʶ��ͨ
// Modified by Venus Oct.1997

#include <ansi.h>

//inherit SSERVER;

int conjure(object me, object target)
{
    int     delta;
    if( target ) return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�á�\n");
    if( me->query("jingli") < 30 )
   return notify_fail("�������������\n");
    me->add("jingli", -30);
    me->receive_damage("jing", 10);
    message_vision(HIY "$N��ϥ������һ����������ʼ��˼�붨����\n" NOR, me);
    if( random(me->query_skill("magic")) > (int)me->query_int() ) {
    if( random(me->query("max_jingli")) < (int)me->query("jingli")/2 )
 {
    me->add("learned_points", 1);
    write( HIR "��ֻ��������һ���ң����Ǳ�ܽ����ˣ�\n" NOR);
    return 1;
   }
    if( ((int)me->query("potential") - (int)me->query("learned_points")) < 500 )
    {
    delta = random((int)me->query_con() + (int)me->query_skill("bashi-shentong") )/10;
   if( delta > 0 )
   {
      me->add("potential", random((int)me->query_con() + (int)me->query_skill("bashi-shentong") )/10);
      write( HIG "���Ǳ�ܻ������ˣ�\n" NOR );
      return 1;
   }
    }
    }
    write("����ֻ����һ������\n");
    return 1;
}

