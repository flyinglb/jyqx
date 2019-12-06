#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string code="����(GB)";
        int suc=0;
        if(arg && arg != ""){
                arg = lower_case(arg);
                switch(arg)
                {
                case "gb": me->set_encoding(0);suc=1;code="����(GB)";break;
                case "big5": me->set_encoding(1);suc=1;code="������(BIG5)";break;
                default: break;
                }
        }
        if(!suc && me->query_encoding() == 1) code = "������(BIG5)";
        printf("������ʹ�õ�����Ϊ��%s��\n",code);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : code [GB|BIG5]

���ָ�����ʹ���ڱ���̶����ʱ�л����ĵ������ʽ��ʹ֧֮��GB(������)
��BIG5(������)��
HELP
    );
    return 1;
}
