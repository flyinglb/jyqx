// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
	if (me->is_fighting()) {
		me->remove_all_enemy();
                message_vision("$N�������һԾ������սȦ�����ˡ�\n", me); 
	}
	else if (!me->is_busy()) 
		return notify_fail("�����ڲ�æ��\n");
	else if ((int)me->query_temp("pending/exercise") != 0) {
	        message_vision("$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
		me->interrupt_me();
	}
	else if ((int)me->query_temp("pending/respirate") != 0)
		me->interrupt_me();
        if((int)me->query_temp("fight_tongren") > 0)
                me->add_temp("fight_tongren",-1);
	me->interrupt_me();

	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : halt
 
���ָ������ͣ���������ɵ����飬����ֹͣ���������ŵȡ�

HELP
    );
    return 1;
}
