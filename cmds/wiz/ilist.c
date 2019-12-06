// ilist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("ָ���ʽ��ilist <�������>\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), arg));
	if( !ob ) return notify_fail("û������������������û�б����롣\n");

	printf("%Oֱ�ӻ��Ӽ̳����µ�����\n    %s\n", ob,
		implode(deep_inherit_list(ob), "\n    "));
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: ilist <�������>
 
�г�һ��������̳е����������
 
HELP
);
        return 1;
}
 
