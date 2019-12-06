// cpu.c
// added by atu@sjfy
inherit F_CLEAN_UP;
int main()
{
	mapping info;
	float x,y,z,fraction;
	
	info = rusage();
	x = (info["utime"] + info["stime"])/1000;
	fraction = x / uptime();
	x=to_float(info["load1"])/100;
	y=to_float(info["load10"])/100;
	z=to_float(info["load15"])/100;


	write(sprintf("\n\nCPUռ����:\n\t��ȥһ������ %2.2f%%
\t��ȥ10������ %2.2f%%\n\t��ȥ15������ %2.2f%%\n������������ ���ͷ��� ����������\n\tƽ��ռ����Ϊ %2.2f%%\n\n"
              ,x,y,z,fraction*100));
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : cpu

���ָ����ʾ��Ŀǰ CPU ��ʹ����, cmds/s��ÿ�����cmds��
comp lines/s ��ÿ�����������
HELP );
    return 1;
}
