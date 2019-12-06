// steal.c
// modified by wind

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string what, who;
   object ob, victim;
//   mapping myfam, vtfam;
   mapping myfam;
   int sp, dp;

   if( environment(me)->query("no_fight")) return notify_fail("�����ֹ���ԡ�\n");
   if( environment(me)->query("no_steal")) return notify_fail("�����ֹ���ԡ�\n");

   if( me->query_temp("stealing") )
      return notify_fail("���Ѿ����һ��������ˣ�\n");

   if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
      return notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

   
   victim = present(who, environment(me));
   
   if( !victim || victim==me) return notify_fail("�������ԵĶ��������\n");
   if( !living(victim) ) return notify_fail("��������ǲ��ǻ���\n");
   // by cmd 2000.12.18

   if( !wizardp(me) && wizardp(victim) )
      return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����\n");

   if( !ob = present(what, victim) )
   {
      object *inv;
      inv = all_inventory(victim);
      if( !sizeof(inv) )
         return notify_fail( victim->name() + "���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
      ob = inv[random(sizeof(inv))];
   }

   if( ob->query("no_get") ) 
      return notify_fail("������Ʒ��͵������\n");

   sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
        - (int)me->query("thief") * 20;

   if ( (myfam = me->query("family")) && myfam["family_name"] == "ؤ��" )
      sp = (int)me->query_skill("stealing") * 10 + (int)me->query("kar") * 5
           - (int)me->query("thief") * 20;

   if( sp < 1 ) sp = 1;

   if( me->is_fighting() )
   {
       sp /= 2;
       me->start_busy(3);
   }
   dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
   if( victim->is_fighting() ) dp *= 10;
   if( ob->query("equipped") ) dp *= 10;

   write("�㲻����ɫ����������" + victim->name() + "���ȴ��������� ...\n\n");

   me->set_temp("stealing", 1);
   call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

   return 1;
}

protected void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
//   mapping myfam, vtfam;
   mapping myfam;
   int steal_level;
   me->delete_temp("stealing");

   if( environment(victim) != environment(me) )
   {
      tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
      return;
   }

   if( !ob = present(ob->query("id"), victim) ) {
      tell_object(me, "̫��ϧ�ˣ���Ҫ͵�Ķ����Ѿ�����Ŀ�������ˡ�\n");
      return;
   }
   if( !living(victim) || (random(sp+dp) > dp) )
   {
      if( ob->query("no_steal") )
      {
         tell_object(me, "������һ" + ob->query("unit") + ob->name()
                       + "��������ͻȻ�������飬��Ȼ�������֣����ǿ�ϧ�ˡ�\n");
         return;
      }
      if( !ob->move(me) )
      {
         tell_object(me, "������һ" + ob->query("unit") + ob->name()
                       + "�����Ƕ������̫���ˣ����ò�������\n");
         return;
      }

      tell_object(me, HIW "�����ˣ�\n\n" NOR);
      tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + ob->name() + "��\n");
      steal_level = (int)me->query_skill("stealing",1);

      if( living(victim) )
      {
         if ((int)me->query("combat_exp") > (steal_level*steal_level*steal_level/10) )
         {
            me->improve_skill("stealing", random(me->query("int")));
         }
         else
         {
            tell_object(me," ����㾭��ҲҪȥ͵�� \n");
         }
         if ( (myfam = me->query("family")) && myfam["family_name"] == "ؤ��" )
         {
            if (( (int)me->query("potential") - (int)me->query("learned_points") < 100))
            {
               me->add("potential",1);
            }
//add by Java. Nov 16.1997
            me->start_busy(2);
            me->add("thief", 1);
            me->add("jing",-10);
            me->add("eff_jing",-4);

            me->add("combat_exp",1);
         }
      }

      if( random(sp) < dp/2 )
         message("vision", "�㿴��" + me->name() + "�������ش�"
               + victim->name() + "����͵����һ" + ob->query("unit")
               + ob->name() + "��\n", environment(me), ({ me, victim }) );
   }
   else
   {
      if( random(sp) > dp/2 )
      {
         tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n"
            "���ã�û�б����֡�\n");
         return;
      }
      tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
      message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n"
            + "$N�ȵ�������ʲô����\n\n", victim, me);
      me->improve_skill("stealing", 1, 1);
      if( userp(victim) ) victim->fight_ob(me);
      else victim->kill_ob(me);
      me->fight_ob(victim);
      me->start_busy(3);
      me->add("thief", 1);
      me->add("jing",-10);
      me->add("eff_jing",-4);
   }

}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, �����ʲô����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}

