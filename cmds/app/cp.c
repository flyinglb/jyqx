// cp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("指令格式: cp <原档名> <目标档名> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

	if( cp(src, dst) ) {
                log_file("edit/"+geteuid(me), sprintf("cp %s %s %s\n", src, dst, ctime(time())) );
                write("Ok.\n");
	} else
		write("复制错误：无效的文件名。\n");
	return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : cp <原档名> <目标档名>
 
此指令可让你(你)拷贝档案。
HELP
    );
    return 1;
}
 
