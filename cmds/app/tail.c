// tail.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    	if (!arg) return help(me);
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");
        write(tail(file,10));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : tail <����>

��ָ�������(��)ֱ�Ӷ�ȡĳ������ĩβ�ļ��С�
HELP
    );
    return 1;
}
