// modify by unix
#include <weapon.h>
#include <ansi.h>
#include <login.h>
inherit NPC;
int time=0;
//void init_data ();
void create()
{
	set_name(this_player()->name(), ({"点歌台"}));
	set("long", @LONG
ｔｈｉｓ  ｉｓ  ａ  ｔｏｐ  ｍｕｓｉｃ  ｃｄ\n
LONG);
	set("attitude", "friendly");
	setup();
	set_heart_beat(1);
}
void init()
{
	add_action("do_start", "start");
	add_action("do_stop", "stop");
}
void heart_beat()
{
object ob;
	this_object()->set_temp("sing", 1);
	this_player()->set_temp("sing",1);
	time++;
	if(time==1)
{
	message("system", HIC""+this_player()->name()+HIR"
	大声宣布：下面"+this_player()->name()+"为大家点一首：\n\n"+
HIW"		<<冰雨>>"NOR
HIW"	想听的请用(music)否则可以使用(tune music)关了\n"+
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n我是在等待一个女孩\n\n还是在等待尘缘苦海．．．\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n一个人默默走开．．．\n\n确不懂花泄花开．．．．\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n好好的一分爱．．啊怎么能让它变坏\n\n冷冷的冰雨在脸上胡乱的拍\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n我的心仿拂被刺刀恨恨的宰\n\n悬崖上的爱．．．啊．．\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n一曲唱过，"+this_player()->name()+"流下了深情的眼泪。\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
