#include <ansi.h>

void do_nothing(string nothing);

int main(object who,string arg)
{   
    write(REF);
    if(arg=="-l")
    input_to( (:do_nothing:) );
    return 1;
}

int help()
{
    write(@HELP
ָ���ʽ��cls [-l]
���ָ����������ǰ��Ļ���ݡ�
�����-l����������ݻ���Ļ�����ֻ�����س�����
HELP );
    return 1;
}

void do_nothing(string nothing)
{
    return;
}
