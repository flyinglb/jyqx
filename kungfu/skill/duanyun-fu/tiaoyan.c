// tiaoyan.c ��������֮������ʽ��
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
      return notify_fail("������ʽ��ֻ����ս����ʹ�á�\n");

    if( target->is_busy() )
   return notify_fail(target->name() + "����ֻ��ͷ��Ӭ����ŵ������ɡ�\n");
    msg = HIG "$Nʹ�����Ƹ���֮������ʽ�������⼲��$n˫�ۡ�\n";

    me->start_busy(random(1));
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4
 ) {
    msg += "���$pֻ������ǰһ�ڣ�˫��һ���ʹ������ʲôҲ�������ˡ�\n" NOR;
 target->start_busy( (int)me->query_skill("duanyun-fu") / 20 + 3);
 target->add("eff_qi",-((int)me->query_skill("duanyun-fu")/3));
 target->add("max_qi",-((int)me->query_skill("duanyun-fu")/3));
 target->add("qi",-((int)me->query_skill("duanyun-fu")/3));
    } else {
   msg += "����$p������$P����ͼ������æ�㿪�ˡ�\n" NOR;
    }
    message_vision(msg, me, target);

    return 1;
}

