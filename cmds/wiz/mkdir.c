// mkdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( mkdir(dir) ) {
	        log_file("edit/"+geteuid(me), sprintf("mkdir %s %s\n", dir, ctime(time())) );
		write("Ok.\n");
	} else
		write("����������Ч��Ŀ¼����\n");
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
