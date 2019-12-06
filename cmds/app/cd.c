// cd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;

	if( !arg )
		arg = user_path(me->query("id"));
	dir = resolve_path(me->query("cwd"), arg);
	if(file_size(dir)!=-2) return notify_fail("û�����Ŀ¼��\n");

	if(dir[strlen(dir)-1]!='/') dir += "/";
	me->set("cwd", dir);
	write(dir + "\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
ָ���ʽ : cd <��Ŀ¼��>, cd .. , and cd

��Ŀǰ�ο���Ŀ¼����ָ������Ŀ¼��ص���һ��Ŀ¼; ���ֱ�ӻص��Լ�����Ŀ¼��
HELP
	);
	return 1;
}
