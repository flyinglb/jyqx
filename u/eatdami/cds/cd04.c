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
HIW"		<<笨小孩>>刘德华"NOR
HIW"希望大家喜欢\n"NOR+
HIW"	想听的请用(music)否则可以用(tune music)关掉。\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIR"小声唱道：\n"+
HIY"\n寂静的小村外 有一个笨小孩出生在６０年代\n\n十来岁到城市 不怕那太阳晒 努力
在７０年代\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"放开嗓子唱道：\n"+
HIY"\n发现那城市里 朋友们不用去灌溉 花自然会开\n\n转眼间这一个笨小孩又到了８０
年代\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"温柔的唱着：\n"+
HIY"\n三十岁到头来 不算好也不坏 经过了９０年代\n\n最无耐他总是慢人家一拍 没有钱
在那口袋\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"继续唱道：\n"+
HIY"\n哎唷．．往着胸口拍一拍呀 勇敢站起来\n\n不用心情太坏．．．．\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"最后高歌\n"+
HIY"\n哎唷．．向着天空拜一拜呀 别想不开\n\n老天自有安排(老天爱笨小孩)\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"哭着唱道：\n"+
HIY""+this_player()->name()+"唱完朗声道：谁与共唱一首<<笑傲江湖>>\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
