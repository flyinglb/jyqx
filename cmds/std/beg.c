// beg.c
//Modified by Eatdami@MX (10/06/2000)

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        mapping myfam, vtfam;
        int sp, dp;

//        object where = environment(me);

        seteuid(getuid());

        if ( (!(myfam = me->query("family")) || myfam["family_name"] != "ؤ��"))
          return notify_fail("ֻ����ؤ�������֣�\n");

        if( environment(me)->query("no_beg") || environment(me)->query("no_fight"))
                return notify_fail("���ﲻ����л��������ַ��ĵط���\n");

        if( me->query_temp("begging") )
                return notify_fail("���Ѿ������˼������ˣ�\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
                return notify_fail("ָ���ʽ��beg <��Ʒ> from <����>\n");

        victim = present(who, environment(me));
        if( !victim || victim == me) return notify_fail("�������ֵĶ��������\n");
        if( !living(victim) || !objectp(victim)) return notify_fail("��Ҫ��˭���֣�\n");
        if( victim->query("no_beg_from") || wizardp(victim))
                return notify_fail("���ǲ��������л��ӵģ�\n");
        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "ؤ��" )
                return notify_fail("�㲻������ؤ���֣�\n");

        if( !wizardp(me) && wizardp(victim) ) return notify_fail("��Ҳ�������ʦ���֡�\n");

        if( me->is_fighting() )
                return notify_fail("һ�ߴ��һ��Ҫ���������ǻ����ˣ�\n");

	if((int)me->query("age") <= 18 && userp(victim))
	        return notify_fail("��С������������ϰ�ߣ���������ô���ˣ�\n");

        if( victim->is_fighting() )
                return notify_fail(victim->name() + "���ڴ�ܣ�û�����㣡\n");

        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + "���Ͽ�����û��ʲ���������Ȥ�Ķ�����\n");
                ob = inv[random(sizeof(inv))];
        }

//modified by eatdami
        if ( ob->query("equipped") || ob->query("no_drop") || ob->query("no_steal"))
                return notify_fail("�������˵�����һ�϶�������㡣\n");

        sp = (int)me->query_skill("begging") * 15 + (int)me->query("kar") * 5
                - (int)me->query("begger") * 2;
        if( sp < 1 ) sp = 1;
        dp = (int)victim->query("jing");

        tell_object(me, "��װ�������Ͱ͵����ӣ���������" + victim->name() + "�߹�ȥ�����˫�֣���Ҫ"
                        + ob->query("unit") + ob->name() +"...\n\n");
        tell_object(victim, me->name() + "�����Ͱ͵����������߹���������֣�˵����" + RANK_D->query_respect(victim) + "���кã�����"
                        + ob->query("unit") + ob->name() + "�� ...��\n\n");
        message("vision", "ֻ��" + me->name() + "װ�������Ͱ͵����ӣ���������"
                + victim->name() + "�߹�ȥ��\n���˫�֣�˵����"
                + RANK_D->query_respect(victim) + "�����кð� ...\n\n", environment(me), ({ me, victim}) );

        me->set_temp("begging", 1);
        call_out( "compelete_beg", 3, me, victim, ob, sp, dp);
        return 1;
}

protected void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
        int amount, begging_level;
        object ob1;
        object where;

        if( !me ) return;
        where = environment(me);

        me->delete_temp("begging");

        if( environment(victim) != environment(me) ) {
                tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
                return;
        }
        if( !ob = present(ob->query("id"), victim) ) {
                tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵĶ����Ѿ�����Ŀ�������ˡ�\n");
                return;
        }

        if( living(victim) && (random(sp+dp) > dp) )
        {
                if ( ob->query("money_id") )
                {
                        amount = ob->query_amount();
                        if( amount < 5 )
                        {
                                tell_object(me, "���������߰ɣ���һ������Ѿ�û�ж�����ˮ��ե�ˡ�\n");
                                return;
                        }

                        ob->set_amount(amount - amount/5);

                        ob1=new("/clone/money/" + ob->query("money_id"));
                        ob1->set_amount(amount/5);
                        ob1->move(me);

                }
                else if( !ob->move(me) ) {
                        ob->move(where);
                        tell_object(me, "���ֵ�һ" + ob->query("unit") + ob->name()
                                + "�����Ƕ������̫���ˣ����ö��ڵ��¡�\n");
                        return;
                }

                tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬ҡҡͷ��̾�˿�����������һ"
                                + ob->query("unit") + ob->name() + "��\n");
                tell_object(victim, "�㿴��" +  me->name() +"�Ŀ�������̾�˿�����������һ"
                                + ob->query("unit") + ob->name() + "��\n");
// �����ֹǱ�ܺͼ��ܴ���������
      begging_level = me->query_skill("begging", 1);
      if ( (int)me->query("combat_exp") > (begging_level*begging_level*begging_level)/10)
         {
          me->improve_skill("begging", random(me->query("int")));
         }  else {
                 tell_object (me, "����㾭��ֵҲȥ�л������Ǳ�ȥ������!\n");
                  }
      if (( (int)me->query("potential")-(int)me->query("learned_points") < 1000))
                me->add("potential",2);
                me->add("combat_exp",10);

                if( random(sp) < dp/2 )
                        message("vision", "�㿴��" + victim->name() + "����" + me->name() + "������м��ҡҡͷ��"
                                + "������һ" + ob->query("unit")
                                + ob->name() + "��\n", environment(me), ({ me, victim }) );
                me->add("jing",-8);
                me->add("eff_jing", -2);
                me->start_busy(6);
        }
        else
        {
                if( random(sp) > dp/2 ) {
                        message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ������� $N����һ������æŤͷ��������߿��ˡ�\n", me);
                        me->add("begger", 1);
                        me->add("jing",-4);
                        me->add("eff_jing", -2);
                        return;
                }

                tell_object(me, victim->name() + "Ť��ͷȥ������������\n");
                tell_object(victim, "��Ť��ͷȥ����" + me->name() + "������\n");
                message("vision", victim->name() + "Ť��ͷȥ����" + me->name() +  "������\n",
                        environment(me), ({ me, victim }) );

                me->start_busy(3);
        }
}

int help(object me)
{
write(@HELP
ָ���ʽ : beg <ĳ��> from <ĳ��>

HELP
    );
    return 1;
}

