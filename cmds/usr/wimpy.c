// wimpy.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	int wmp;

	if( !arg ) {
		write("�����ڵĵ���������� " + (int)me->query("env/wimpy") 
			+ "% ʱ�ͻ᳢�����ܡ�\n");
		return 1;
	}
	if( sscanf(arg, "%d", wmp)!=1 || wmp < 0 || wmp > 80)
		return help(me);

	me->set("env/wimpy", wmp);
	write("Ok.\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ�� wimpy [<����ʱ�������İٷֱ�>]

���ָ�������趨��������ʣ�°ٷ�֮����ʱ��Ҫ��ʼ��ת������
HELP
	);
	return 1;
}

