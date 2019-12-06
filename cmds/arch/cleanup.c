// cleanup.c

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object *ob_list;
	int old_size, i;

	if (!str) return notify_fail("ָ���ʽ��cleanup <����>\n"); 

	str = resolve_path(me->query("cwd"), str);
	ob_list = children(str);
	old_size = sizeof(ob_list);
	ob_list->clean_up();
	for(i=0; i<sizeof(ob_list); i++)
		if( ob_list[i] && clonep(ob_list[i]) && !environment(ob_list[i]) )
			destruct(ob_list[i]);
	ob_list -= ({ 0 });
	printf("��� %d �������\n", old_size - sizeof(ob_list));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��cleanup <����>

������ָ��������������� clean_up������������б����Ƴ����ģ�������û��
��������һ������е�ɢʧ�����
HELP
	);
	return 1;
}

