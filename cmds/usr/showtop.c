// from fy by wind

inherit F_CLEAN_UP;
int main(object me)
{
	string output;
	output = STATUS_D->show_top();
        me->start_more(output);
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : showtop

���ָ����ʾ��Ŀǰ��ҵĽ����ٶȣ���������Կ����Ƿ�������BUG��ROBOT.
HELP
    );
    return 1;
}
