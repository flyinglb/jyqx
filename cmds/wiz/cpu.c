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


	write(sprintf("\n\nCPU占用率:\n\t过去一分钟内 %2.2f%%
\t过去10分钟内 %2.2f%%\n\t过去15分钟内 %2.2f%%\n────── 世纪风云 ─────\n\t平均占用率为 %2.2f%%\n\n"
              ,x,y,z,fraction*100));
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : cpu

这个指令显示出目前 CPU 的使用率, cmds/s是每秒编译cmds数
comp lines/s 是每秒编译行数。
HELP );
    return 1;
}
