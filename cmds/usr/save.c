// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

        if( (time() - (int)me->query_temp("last_save_time")) < 300 
        && !wizardp(me) )
                return notify_fail("你刚刚才存储过先等一会吧。\n");
	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("你不是经由正常连线进入，不能储存。\n");

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write("当你下次连线进来时，会从这里开始。\n");
	}

/*
        write("档案储存完毕。\n");
        return 1;
*/
        if( (int)link_ob->save() && (int)me->save() ) {
        write("档案储存完毕。\n");
        me->set_temp("last_save_time", time());
		return 1;
	} else {
		write("储存失败。\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：save

把你辛苦奋斗的结果存起来。
HELP
	);
	return 1;
}
