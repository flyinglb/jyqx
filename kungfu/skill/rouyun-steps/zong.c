// zong.c�������ݡ�
// modified by Venus Oct.1997
#include <ansi.h>
#include <command.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
if( !me->is_fighting() )
      return notify_fail("�������ݡ�ֻ����ս����ʹ�á�\n");
if( (int)me->query_skill("rouyun-steps",1) < 50 )
      return notify_fail("������Ʋ�������������\n");
if( (int)me->query("jingli") < 50 )
      return notify_fail("��ľ���������\n");
      msg = HIC "$N���ζ�Ȼ����ʮ�����ţ������ȴƮ��һ���ƣ��ǳ���֣�\n" NOR;
   me->receive_damage("jing", 10);
   me->add("jingli", -20);
   me->set_temp("no_follow",1);
   msg += HIC"ԭ��$N��ʹ���������ݡ������ƶ�ȥ�ˣ�\n"NOR;
    message_vision(msg, me, target);
    switch( random(3) ) {
    case 0:
    me->move("/d/city/wumiao");
    break;
    case 1:
    me->move("/d/city/kedian");
    break;
    case 2:
    me->move("/u/deaner/test1");
    break;
}
    return 1;
}
