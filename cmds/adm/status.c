// status.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string msg;

	msg = (string)mud_status(arg=="detail" ? 1 : 0);
	if( stringp(msg) ) write(msg);

	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : status [detail]
 
���ָ�������ʾ��Ŀǰ��Ϸ��һЩ������ϼ�״��.
 
HELP
    );
    return 1;
}
 
