// modify by unix
#include <weapon.h>
#include <ansi.h>
#include <login.h>
inherit NPC;
int time=0;
//void init_data ();
void create()
{
	set_name(this_player()->name(),({"cd-2"}));
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
	羞嗒嗒的说：下面我为大家演唱一首\n\n"+
HIW"		<<恋恋风尘>>"NOR
HIW"希望大家喜欢\n"NOR+
HIW"	想听的请用(music)否则可以用(tune music)关掉。\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIR"小声唱道：\n"+
HIY"\n那天，黄昏，开始飘起了白雪\n\n忧伤，开满山岗，等青春散场\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"放开嗓子唱道：\n"+
HIY"\n午夜的电影，写满古老的恋情\n\n在黑暗中，为年青歌唱．．\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"温柔的唱着：\n"+
HIY"\n走吧，女孩，去看红色的朝霞\n\n带上我的恋歌，你迎风歌唱\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"继续唱道：\n"+
HIY"\n露水挂在发梢，结满透明的愁怅\n\n是我一生中最初的迷惘\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"最后高歌\n"+
HIY"
\n当岁月已成风中的叹息\n\n你感伤的眼里有旧时泪滴\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"哭着唱道：\n"+
HIY"\n相信爱的年纪没能唱给你的歌曲\n\n让我一生中常常追忆\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
