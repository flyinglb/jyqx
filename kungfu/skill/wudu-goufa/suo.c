 // suo.c  ������
 // by zxx
 inherit F_SSERVER;

 int perform(object me, object target)
 {
          object ob,weapon,myweapon;
        string msg;
         int skill,myskill;
         if( !target ) target = offensive_target(me);

         if( !me->is_fighting() )
                 return notify_fail("�������꡹ֻ����ս����ʹ�á�\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
               return notify_fail("�������꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

         if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                 return notify_fail("�������꡹��ʼʱ��������һ�ѽ���\n");

         if( (int)me->query("neili") < 100 )
                 return notify_fail("�������������\n");

         if( (int)me->query_skill("sword",1) < 50 ||
             me->query_skill_mapped("sword") != "wudu-goufa")
                 return notify_fail("����嶾�����������ң��޷�ʹ�ý����꣡\n");

         if( (int)me->query_skill("wudu-goufa",1) < 50 )
                 return notify_fail("����嶾�����������ң��޷�ʹ�ý����꣡\n");

         if (!objectp(weapon = target->query_temp("weapon")))
                 return notify_fail("�Է����в�û�б�����\n");

        weapon=target->query_temp("weapon");
        myweapon=me->query_temp("weapon");
         message_vision(HIR "\n$N���һ�У�����"+myweapon->query("name")+"����һ���������Ѵ���$n��"+weapon ->query("name")+HIR"�ϣ�\n" NOR,me,target);
        skill = target->query_skill("parry",1);             // 32
        myskill = me->query_skill("wudu-goufa",1);
        if(random(myskill) < random(skill/2)||me->query("max_neili") <random(target->query("max_neili"))){
              msg = HIY "����$n����׼������æ����������\n" NOR;
             message_vision(msg, me,target);
             me->start_busy(3);
             me->add("neili",-100);
             return 1; 
        }

         msg = HIR "ֻ��$N˳��һ�ʣ��ͺ�һ���������֣���$nֻ���û���һ���ʹ��\n����"+weapon->query("name")+HIR"���һ�����ڵ��ϣ�\n" NOR;
        message_vision(msg,me,target);
         msg = "$N����һЦ���������ˣ����н��ƣ�\n" NOR;
        message_vision(msg, me,ob);
         me->clean_up_enemy();
         ob = me->select_opponent();
        weapon->move(environment(me));

         COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
         COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
         COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
         COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
         COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        ob->start_busy(4);
         me->add("neili", -100);
         me->start_busy(2);
         return 1;
 }
