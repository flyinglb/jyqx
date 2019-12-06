// cp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cp <ԭ����> <Ŀ�굵��> \n");

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
		write("���ƴ�����Ч���ļ�����\n");
	return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : cp <ԭ����> <Ŀ�굵��>
 
��ָ�������(��)����������
HELP
    );
    return 1;
}
 
