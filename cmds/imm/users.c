

#include <ansi.h>

inherit F_CLEAN_UP;

mixed main(object me)
{
	object *ob;
	int i, ppl_cnt, cnt, wcnt = 0;

	ob = filter_array(objects(), (: userp :));
	ppl_cnt = 0;
	cnt = 0;
	i = sizeof(ob);
	while( i-- ) {
        if (!environment(ob[i])) continue;
	        if (wizardp(ob[i])) wcnt++;
		else if (interactive(ob[i])) ppl_cnt++;
		else cnt++;
	}
	
	write("\n"+MUD_NAME+"目前共有 "+wcnt+" 位巫师， "+ppl_cnt+" 位玩家连线中，"+cnt+" 位玩家断线中。
系统负担："+query_load_average()+"。
现在的 time() 是：" + time() + "。
现在的 uptime() 是：" + uptime() + "。\n\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : users

这个指令可以列出目前的玩家数量。

相关指令： who
HELP
	);
	return 1;
}
