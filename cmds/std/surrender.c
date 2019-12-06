// surrender.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	
	if( !me->is_fighting() )
		return notify_fail("Ͷ��������û�����ڴ��㰡....��\n");

	ob = me->query_temp("last_opponent");
	if( objectp(ob) && living(ob) && ob->is_killing(me) ) {
		message_vision("$N��$n���ģ�����$N����˵����"
			+ RANK_D->query_rude(me) + "�ϻ���˵����������\n", ob, me);
		return 1;
	}

	me->remove_all_enemy();
	if( (int)me->query("score") >= 50 )
		me->add("score", -50 );
	else
		me->set("score", 0);

	message_vision( HIW "\n$N˵�����������ˣ������ˣ���Ͷ��....����\n\n" NOR, me);
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : surrender
 
���ָ��������������Ͷ������ֹս����
 
HELP
    );
    return 1;
}
 
