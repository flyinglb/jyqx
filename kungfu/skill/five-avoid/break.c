// break.c ��ݾ�ɱ
// Modified by Venus Oct.1997
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int count;
if( !me->is_fighting() )
      return notify_fail("����ݾ�ɱ��ֻ����ս����ʹ�á�\n");
if( (int)me->query("qi") < 70 )
      return notify_fail("�����������\n");
if( (int)me->query("max_neili") < 100 )
      return notify_fail("�������������\n");
if( (int)me->query("neili") < (int)me->query("max_neili")/2)
      return notify_fail("�������������\n");
msg = HIC "$Nʹ�����ж��еġ���ݾ�ɱ��������Ȼ���ñ��Ī�⣡\n" NOR;
message_vision(msg, me);
count = (int)me->query_skill("five-avoid") / 20 + 2;
   if( count > 5 ) count = 5;
   while( count-- )
 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_vision(WHT "$N������ٿ��һת������ͣס�˽Ų���\n" NOR, me);
     break;
   }
  else

  message_vision(WHT "$N����Ӱ��$n����ʱ��ʱ�� ...\n" NOR, me, ob);
  if( !COMBAT_D->fight(me, ob) )
      message_vision(WHT "����$Nʼ��û���ҵ�������֣�\n" NOR, me);
  me->receive_damage("qi", 10);
  me->add("neili", -10);
 }
    me->start_busy(1);
    return 1;
}

