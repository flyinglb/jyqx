// mkdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( mkdir(dir) )
		write("Ok.\n");
	else
		write("��û�������ｨ��Ŀ¼��Ȩ����\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
ָ���ʽ : mkdir <��Ŀ¼��>

����һ����Ŀ¼��
HELP
	);
	return 1;
}
