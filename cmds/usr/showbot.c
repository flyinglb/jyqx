// from fy by wind

inherit F_CLEAN_UP;
int main(object me)
{
	string output;
	output = STATUS_D->show_bot();
        me->start_more(output);
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : showbot

���ָ����ʾ��Ŀǰ��ҵĽ����ٶȣ���������Կ���һЩ��ҵ�DUMMY.
HELP
    );
    return 1;
}
