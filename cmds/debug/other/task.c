// by Tie@fy3 hehe
#include <ansi.h>
int main(object me, string str)
{
	string output;
	output = HIR"◎  "HIG"新金庸群侠"HIR"传遗失物品表：\n" NOR;
	output += "———————————————————————————\n";
	output += TASK_D->dyn_quest_list();
	output += "———————————————————————————\n\n";
	me->start_more(output);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: task

这个指令是用来得知目前的所有使命.

HELP
	);
	return 1;
}
