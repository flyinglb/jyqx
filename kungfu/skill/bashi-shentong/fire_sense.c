// fire_sense.c ��ʶ��ͨ
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;
int conjure(object me, object target)
{
    string msg;
    string msg1;
    string msg2;
    string msg3;
    string msg4;
    int damage, ap, dp,i;
    i=random(3);
    if( !target ) target = offensive_target(me);
    if( !target
     || !target->is_character()
     || target->is_corpse()
     || target==me)
    return notify_fail(HIR"��Ҫ��˭ʩչ����ʶ����\n"NOR);
    if (i==0){
        msg1="$N˫�ָ�����������ٲ�£����һ�ƣ���ȵ���"+HIC"�����������ܣ�����׵硭���򣡣���"NOR+"\n;
        ɲ�Ǽ䣬������ӿ��Ũ���ܲ���һ������������м���������$n��ȥ������\n";
        msg2=HIR"���䡱��һ�����˸����ţ�"+target->query("name")+"���������Ѭ��ͷһ���ڣ�\n"NOR;
        msg3=RED"��ֻ����ȫ���飬��ǰ������ð��������\n"NOR;
        msg4="jing";
    }
    if(i==1){
        msg1="$N����һתɢ���ߴ�ͬʱ���������\n"+HIY"
        ��������࣬�򽣹��ڣ������������񽣷�ħ������"NOR+"\n
        ֻ�����г����������$n��ȥ������\n";

        msg2="ֻ�������͡����첻�����������"+target->query("name")+"���塣"+
        target->query("name")+"�����ǧ���ٿ׵Ĵ�ɸ�ӣ�����\n";
        msg3=RED"��ֻ���ı������磬�����ʹ��\n"NOR;
        msg4="jing";
    }
    if (i==2){
        msg1="$N˫�ֻ�����ǰ�������������\n"+HIR"������޼���Ǭ���跨������"NOR+"\n  
        ͻȻ���һ�������У�����\n˫�Ʋ�����һ�޴�Ľ�ɫ��������$n��\n";
        msg2="���顱��"+target->query("name")+"�������һ���������˼���������\n";
        msg3="���顱�����ؿ����ⴸ��������һ�ڣ���Щ���˹�ȥ��\n";
        msg4="qi";
    }

    if((int)me->query("jingli") < 150 )
        return notify_fail("��ľ���������\n");

    if((int)me->query("jing") < 35 )
        return notify_fail("������ľ����޷���Ч���У�\n");

    me->add("jingli", -30);

    if( random(me->query("max_jingli")) < 150 ) {
       write("��ʧ���ˡ�\n");
       return 1;
    }
    msg="\n";
    message_vision(msg1, me, target);
    ap = me->query_skill("bashi-shentong");
    ap = ( ap * ap * ap / 4 ) * (int)me->query("jing") / 100;
    dp = target->query("combat_exp");
    if( random(ap + dp) > dp) {
       damage = (int)me->query("max_jingli") / 10 + random((int)me->query("eff_jing") / 5);
       damage -= (int)target->query("max_jingli") / 20 + random((int)me->query("eff_jing") / 10);
       if(target->is_ghost()) damage=damage*10;
       if( damage > 0 ) {
        target->receive_damage(msg4, damage, me);
        target->receive_wound(msg4, damage/2, me);
        tell_room(environment(me),msg2,target);
        tell_object(target,msg3);
        me->improve_skill("bashi-shentong", 1, 1);
     } else
     {
        msg = "$N�ġ���ʶ������û������κ��˺���\n";
        me->receive_damage("jing", 10);
     }
   } else
   msg = "����$n����ض㿪�ˡ�\n";
   message_vision(msg, me, target);

   if( damage > 0 ) COMBAT_D->report_status(target);
   if( !target->is_fighting(me) ) {
     if( living(target) ) {
      if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(2);
   return 1;
}

