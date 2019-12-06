// possess.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || me != this_player(1)) return 0;
	ob = present(arg, environment(me));
	if( !ob || !living(ob))
		return notify_fail("����û��������\n");
	if( geteuid(ob) != geteuid(me) )
		return notify_fail( ob->name() + "�� euid " + geteuid(ob) + "����" + geteuid(me) + "���ϣ��޷����и���\n");
	if( ob->query_temp("body_ob") )
		return notify_fail( ob->name() + "�Ѿ����˸�����ˡ�\n");
	message_vision("$N����һ����â���$n���ڡ�\n", me, ob);
	LOGIN_D->enter_world(me, ob, 1);

	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��posssess <Ŀ������>

������һ�������ϣ������������������ͬ�� EUID��
�������� quit ָ���ص�ԭ�������塣
TEXT
	);
	return 1;
}
