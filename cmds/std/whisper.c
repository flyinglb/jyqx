// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;
        
        if((time() - (int)me->query_temp("last_whisper_time") < 5) && !wizardp(me)){
                write("你说话太快了，让人听不清楚。\n");
                return 1;
        }

        seteuid(getuid());
        
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什么？\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("你要对谁耳语？\n");

	write( HIW + "你" +NOR+WHT+ "在" +HIY+ ob->name() + NOR+MAG+ "的耳边悄声说道：" + HIY + msg + "\n" + NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()
		+ "耳边小声地说了些话。\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, HIW + me->name() +NOR+WHT+ "在" +HIY+ "你" +NOR+MAG+ "的耳边悄声说道：" + HIY + msg + "\n" NOR);
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"【窃听】"HIW+me->query("name")+"("+me->query("id")+")"+NOR+MAG+"悄悄告诉"+HIY+ob->query("name")+"("+ob->query("id")+")："+msg+"\n"NOR, users());
        me->set_temp("last_whisper_time",time());
	return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：whisper <某人> <讯息>

这个指令可以用来和同一房间中的人耳语，包括 NPC 在内。
TEXT
	);
	return 1;
}
