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
ָ���ʽ : showpk

���ָ����ʾ��Ŀǰɱ�ֵĽ����ٶȣ���������Կ����Ƿ�������BUG��ROBOT.
HELP
    );
    return 1;
}
