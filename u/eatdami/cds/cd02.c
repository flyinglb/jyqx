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
HIW"		<<同桌的你>>"NOR
HIW"希望大家喜欢\n"NOR+
HIW"	想欣赏的请大开(news)否则可以(tune news)\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIR"小声唱道：\n"+
HIY"\n明天你是否会想起昨天你写的日记\n\n明天你是否会记起曾经最爱哭的你\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"放开嗓子唱道：\n"+
HIY"\n老师们都已想不出猜不出问题的你\n\n我也是偶然翻像片才记起同桌的你\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"温柔的唱着：\n"+
HIY"\n那时候天总是很蓝日子总过的太慢\n\n你说毕业遥遥无期转眼就各奔东西\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"继续唱道：\n"+
HIY"\n谁娶了多愁善感的你\n\n谁安慰爱哭的你\n\n谁把你的长发盘．．起\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"最后高歌\n"+
HIY"\n谁给你做的嫁衣．．．\n\n啦啦啦．．．啦．．啦．．．．\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
