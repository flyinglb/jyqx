// cost.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping before, after;
	int stime, usertime, eval_cost;

	if( me != this_player(1) ) me = this_player(1);

	seteuid(getuid());
   	if(!arg) return notify_fail("ָ���ʽ��cost <ָ��> [<����> ....]\n");

	before = rusage();
	eval_cost = eval_cost();
	me->force_me(arg);
	eval_cost -= eval_cost();
	after = rusage();
	usertime = after["utime"] - before["utime"];
	stime = after["stime"] - before["stime"];
	printf("\nϵͳʱ�䣺%d ΢��\nʹ����ʱ�䣺%d ΢��\nEval cost��%d ��λ\n",
		stime, usertime, eval_cost );
		
	return 1;
}

int help()
{
	write( @TEXT
ָ���ʽ��cost <ָ��> [<����> .... ]

���ָ�����������һ��ָ��ִ�������ʱ�䡣
TEXT
	);
	return 1 ;
}
