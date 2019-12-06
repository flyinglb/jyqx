// by wind

inherit F_CLEAN_UP;
int main(object me)
{
	string output;
	output = STATUS_D->show_pk();
        me->start_more(output);
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : showpk

这个指令显示出目前杀手的进程速度，从这里可以看出是否有人用BUG和ROBOT.
HELP
    );
    return 1;
}
