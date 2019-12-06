// fang.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
	object *inv;
	int j = 0, i = 0;

	inv = all_inventory(environment(me));
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("owner") == me->query("id") )
		{
			message_vision("$N�ܴȱ��ذ�$n���룬����ع���Ȼ�ˡ�\n", me, inv[i]);
			inv[i]->delete_temp("owner");
			inv[i]->delete_temp("ownername");
			j=1;
		}
		i++;
	}
	if (j == 0)
		message_vision("$N�����������ûɶ�ɷŵġ�\n", me);
	
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : release

��ָ���������ĳ���������ū״̬����������롣

HELP
	);
	return 1;
}

