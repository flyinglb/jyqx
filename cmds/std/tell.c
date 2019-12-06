// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;

        if((time() - (int)me->query_temp("last_tell_time") < 4) && !wizardp(me)){
                write("你说话太快了，让人听不清楚。\n");
                return 1;
        }

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

      if( sscanf(target, "%s@%s", target, mud)==2 ) {
              GTELL->send_gtell(mud, target, me, msg);
              write("网路讯息已送出，可能要稍候才能得到回应。\n");
              return 1;
      }

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
        if( obj == me ) return notify_fail("你想对谁说话？\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="all")
		return notify_fail("这个人不想听你罗嗦。\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="ALL")
		return notify_fail("这个人不想听你罗嗦。\n");
	if (!wizardp(me) && obj->query("env/no_tell")==me->query("id"))
		return notify_fail("这个人不想听你罗嗦。\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("正在拱猪的人听不到悄悄话……。\n");

	write(HIG "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIG "%s告诉你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"【窃听】"+HIG+me->query("name")+"("+me->query("id")+")"+HIW+"告诉"+HIG+obj->query("name")+"("+obj->query("id")+")："+msg+"\n"NOR, users());

        me->set_temp("last_tell_time",time());
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)告诉你：%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s 告诉你：%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方的使用者说话。

其他相关指令：reply
HELP
	);
	return 1;
}
