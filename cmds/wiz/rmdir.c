// rmdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( rmdir(dir) ) {
	        log_file("edit/"+geteuid(me), sprintf("rmdir %s %s\n", dir, ctime(time())) );
		write("Ok.\n");
	} else
		write("删除错误：无效的目录名。\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式 : rmdir <子目录名>

删除一个子目录。
HELP
	);
	return 1;
}
