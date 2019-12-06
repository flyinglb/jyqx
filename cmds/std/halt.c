// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
	if (me->is_fighting()) {
		me->remove_all_enemy();
                message_vision("$N身行向后一跃，跳出战圈不打了。\n", me); 
	}
	else if (!me->is_busy()) 
		return notify_fail("你现在不忙。\n");
	else if ((int)me->query_temp("pending/exercise") != 0) {
	        message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
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
指令格式 : halt
 
这个指令让你停下现在所干的事情，比如停止打坐、吐呐等。

HELP
    );
    return 1;
}
