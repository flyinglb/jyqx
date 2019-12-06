// persuade.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	object where = environment(me);
	
	seteuid(getuid());

        if ((!(myfam = me->query("family"))||myfam["family_name"] != "������"))
        return notify_fail("ֻ�ж����ɲ����ö������ˣ�\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("����û���˴򶷣�\n");

	if( me->query_temp("dushi") )
		return notify_fail("���Ѿ���Ȱ�˼Ұն��ˣ�\n");

	if( !arg || sscanf(arg, "%s stop", who)!=1 ) return
		notify_fail("ָ���ʽ��quanjia|persuade <����> stop\n");

	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("�����ҵĶ��������\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("��ҪȰ˭�ն���\n");

	if( !victim->is_fighting() )
		return notify_fail("�˼�û�ڴ򶷰���\n");

	if ((vtfam = victim->query("family")) && vtfam["family_name"] == "������" )
		return notify_fail("�㲻�����ɵ�ʹ�ö������ˣ�\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("��Ҳ���Ȱ��ʦ�ն���\n");

	if( me->is_fighting() )
                return notify_fail("һ�ߴ��һ��Ȱ���˰ն�����������α�����ˣ�\n");


	sp = (int)me->query_skill("persuading",1) + (int)me->query("kar") * 5;
	if( sp < 1 ) sp = 1;
	dp = (int)victim->query("jing");

	tell_object(me, "��ҡҡ��ͷ����������" + victim->name() + "�߹�ȥ��˫�ֺ�ʮ����ʼ���з�"
			+ "...\n\n");
	tell_object(victim, me->name() + "ҡҡ��ͷ���������߹�����˫�ֺ�ʮ��˵�����ҷ�ȱ��նȶ�����, ����" + RANK_D->query_respect(victim) + "�ն�, ���������� ...��\n\n");

	message("vision", "ֻ��" + me->name() + "ҡҡ��ͷ����������" 
		+ victim->name() + "�߹�ȥ��\n��˫�ֺ�ʮ��˵��: ��"
		+ RANK_D->query_respect(victim) + "��ͣ�ְ� ...\n\n", environment(me), ({ me, victim }) );

	me->set_temp("dushi", 1);
	call_out( "compelete_dushi", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_dushi(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;
	object where = environment(me);

	me->delete_temp("dushi");

	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ���Ҫ�ҵ����Ѿ����ˡ�\n");
		return;
	}

	if( living(victim) && (random(sp+dp) > dp) ) 
	{
		victim ->remove_all_enemy();
		tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬ҡҡͷ��̾�˿�����ֹͣ�˴򶷡�\n");
		tell_object(victim, "������֮�����в���һ�����������������ȥ�ˡ�\n");

		me->improve_skill("persuading", 2 * random(me->query("int")));
		if(((int)me->query("learned_points") + 120) > (int)me->query("potential"))
			me->add("potential",1);
		me->add("combat_exp",2);

		me->start_busy(3);
	} 
	else 
	{
		if( random(sp) > dp/2 ) {
			message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ����Ҷ������˸������ˣ��ܰն���! $N̾�˿���ת���߿��ˡ�\n", me);
			
			return;
		}
	
		tell_object(me, victim->name() + "Ť��ͷȥ������������\n");
		tell_object(victim, "��Ť��ͷȥ����" + me->name() + "������\n");
		message("vision", victim->name() + "Ť��ͷȥ����" + me->name() + "������\n", 
			environment(me), ({ me, victim }) );

	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : persuade | quanjia <ĳ��> stop

HELP
    );
    return 1;
}
