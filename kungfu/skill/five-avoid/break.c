// break.c 五遁绝杀
// Modified by Venus Oct.1997
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int count;
if( !me->is_fighting() )
      return notify_fail("「五遁绝杀」只能在战斗中使用。\n");
if( (int)me->query("qi") < 70 )
      return notify_fail("你的气不够！\n");
if( (int)me->query("max_neili") < 100 )
      return notify_fail("你的内力不够！\n");
if( (int)me->query("neili") < (int)me->query("max_neili")/2)
      return notify_fail("你的真气不够！\n");
msg = HIC "$N使出五行遁中的「五遁绝杀」，身法陡然间变得变幻莫测！\n" NOR;
message_vision(msg, me);
count = (int)me->query_skill("five-avoid") / 20 + 2;
   if( count > 5 ) count = 5;
   while( count-- )
 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_vision(WHT "$N的身形倏地一转，收身停住了脚步。\n" NOR, me);
     break;
   }
  else

  message_vision(WHT "$N的身影在$n身旁时隐时现 ...\n" NOR, me, ob);
  if( !COMBAT_D->fight(me, ob) )
      message_vision(WHT "但是$N始终没有找到机会出手！\n" NOR, me);
  me->receive_damage("qi", 10);
  me->add("neili", -10);
 }
    me->start_busy(1);
    return 1;
}

