// rehash.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg )
		return notify_fail("ָ���ʽ��rehash <·��>\n");

	if( arg[strlen(arg)-1]!='/' ) arg += "/";
	if(  file_size(arg)!=-2 )
		return notify_fail("û�����Ŀ¼��\n");

	write("����ָ���" + arg + "\n");
	COMMAND_D->rehash(arg);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��rehash <Ŀ¼����>

���ָ������ϵͳ�ڲ���ָ��������������ɾ����ĳ��Ŀ¼�µ�ָ�������
���ָ����¸�Ŀ¼����ʹ�á�
HELP
	);
	return 1;
}
