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
HIW"		<<孤星泪>>  原唱：刘德华\n"NOR+
HIW"	想听的请用(music)否则可以用(tune music)关掉。\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n我是一滴远方孤星的泪水，藏在你身上已几万年\n\n所有你的心事都被我看见，让
	我温暖你的脸．．．\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n悄悄滑落在你脸旁．．．\n\n从你红色而又深沉的眼眶，离别时的吻\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n你有太多感伤，我滚烫而又失去了方向\n\n掺绕这那风中依稀的灯光\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n没有了选择，你让我流浪．．\n\n流浪在夜空，流浪使我不在寂寞．．．\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"
\n我是一滴远方孤星的泪水，藏在你身上已几万年\n\n所有你的心事都被我看见\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n让我温暖你的脸．．．\n\n不要再和他见面．．．．\n");
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
