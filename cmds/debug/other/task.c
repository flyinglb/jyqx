// by Tie@fy3 hehe
#include <ansi.h>
int main(object me, string str)
{
	string output;
	output = HIR"��  "HIG"�½�ӹȺ��"HIR"����ʧ��Ʒ��\n" NOR;
	output += "������������������������������������������������������\n";
	output += TASK_D->dyn_quest_list();
	output += "������������������������������������������������������\n\n";
	me->start_more(output);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: task

���ָ����������֪Ŀǰ������ʹ��.

HELP
	);
	return 1;
}
