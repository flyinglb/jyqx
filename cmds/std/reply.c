// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

        if((time() - (int)me->query_temp("last_tell_time") < 3) && !wizardp(me)){
                write("你说话太快了，让人听不清楚。\n");
                return 1;
        }

	if( !arg || arg=="" )
		return notify_fail("你要回答什么？\n");
	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("刚才没有人和你说过话。\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");
/*
	if (!wizardp(me) && obj->query("env/no_tell")=="all")
		return notify_fail("这个人不想听你罗嗦啦。\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="ALL")
		return notify_fail("这个人不想听你罗嗦啦。\n");
	if (!wizardp(me) && obj->query("env/no_tell")==me->query("id"))
		return notify_fail("这个人不想听你罗嗦啦。\n");
*/
	write(HIM "你回答" + obj->name(1) + "：" + arg + "\n" NOR);
	tell_object(obj, sprintf(HIM"%s回答你：%s\n"NOR,
		me->name(1)+"("+me->query("id")+")", arg));
        
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"【窃听】"+HIG+me->query("name")+"("+me->query("id")+")"+HIM+"回答"+HIG+obj->query("name")+"("+obj->query("id")+")："+arg+"\n"NOR, users());
        me->set_temp("last_tell_time",time());
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：reply <讯息>

你可以用这个指令和刚才用 tell 和你说话的使用者说话。

see also : tell
HELP
	);
	return 1;
}
