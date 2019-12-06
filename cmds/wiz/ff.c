// ff.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string dest, func, file;

	if(!arg || sscanf(arg, "%s %s", dest, func)!=2 )
		return notify_fail("ָ���ʽ��ff <���> <��������>\n");

	if( dest=="me" ) ob = me;
	else if( dest=="here" ) ob = environment(me);
	else ob = present(dest, me);

	if( !ob ) ob = present(dest, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), dest));
	if( !ob ) return notify_fail("����û�С�" + dest + "����\n");

	file = function_exists(func, ob);
	if(!file)
		printf("��� %O ��û�ж��� %s ���������\n", ob, func);
	else
		printf("��� %O �� %s ���������� %s.c��\n", ob,	func, file );
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��ff <���> <��������>

���ָ������ҳ�ָ������е�ĳ��������������һ�������
TEXT
	);
	return 1;
}
