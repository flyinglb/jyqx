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
HIW"		<<大头皮鞋>>"NOR
HIW"希望大家喜欢\n"NOR+
HIW"	想听的请用(music)否则可以用(tune music)关掉。\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIR"小声唱道：\n"+
HIY"\n穿起大头皮鞋，想起了我的爷爷\n\n走过了雪山草地，踩破了敌人肚皮\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"放开嗓子唱道：\n"+
HIY"\n那双大头皮鞋传给了我的爹爹\n\n垮过了鸭绿江畔，冲破了三八防线\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"温柔的唱着：\n"+
HIY"\n嘿黝嘿，看我们英雄的祖仙\n\n天不怕地不怕，永往直前\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"继续唱道：\n"+
HIY"\n漂亮的先生小姐穿着漂亮的皮鞋\n\n很多都是进口货，来自日本美国\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"最后高歌\n"+
HIY"
\n我穿着大头皮鞋，走在繁华的大街\n\n虽然有些不起眼，也要走出中国人的尊严\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"哭着唱道：\n"+
HIY"\n嘿黝嘿，革命传统不能丢\n\n不能变，不能变，一年又一年\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
