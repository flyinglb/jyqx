// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

int main(object me, string arg)
{
	me->edit( (: call_other, this_object(), ({ "do_to", me, arg }) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say , tell , describe , chat , reple ........�ȡ�
���� : 
 to say
 �����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��
 ����������������������������������������������������������
 ������̽��� : ����ϯ���ض�
 ����������߷��������� : Elon
 ����С���������㲿���� : ������
 ������ߴ�첿���� : ���Ѫ��
 .

�����өĻ�ϵĽ������ :

��˵����������̽��� : ����ϯ���ض�
����������߷��������� : Elon
����С���������㲿���� : ������
������ߴ�첿���� : ���Ѫ��
HELP
    );
    return 1;
}

