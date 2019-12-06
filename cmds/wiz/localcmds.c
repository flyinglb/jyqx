// localcmds.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	mixed *cmds;
	int i;
	object ob;

	if (!arg) 
		ob=me;
	else
		if (!ob=present(arg,environment(me)))
   			ob=find_player(arg);
	if (!ob) 
		ob=me;
	cmds = ob->query_commands();
	write((ob==me?"��":ob->name(1))+"���ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==ob ) 
			continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}
int help()
{
	write(@TEXT
ָ���ʽ��localcmds
�г������ϼ����ܵ���Ʒ�����ڵĻ����ṩ������ָ�
TEXT
	);
	return 1;
}
