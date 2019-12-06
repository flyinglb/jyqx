// modify by joeblack
#include <weapon.h>
#include <ansi.h>
#include <login.h>
inherit NPC;
int time=0;
//void init_data ();
void create()
{
	set_name(this_player()->name(), ({"cd-41"}));
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
HIW"      歌给一位<<特别的人>>听的"NOR
HIG"希望大家都一起细听\n"NOR+
HIW"    想听的请大开(music)否则可(tune music)一会後再开\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIR"小声唱道：\n"+
HIY"\nI'm not really sure of the words to say\n\nIf only you knew that i feel this way\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"放开嗓子唱道：\n"+
HIY"\nI wanna give my heart to you\n\nshow me the way that you want me to\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"温柔的唱着：\n"+
HIY"\nI know for sure there's a place for us\n\nI'm counting the days till i feel your touch\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"继续唱道：\n"+
HIY"\nYou come to me when i dream at night\n\nWhen I'm with you it will be so right\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"最后高歌\n"+
HIY"\nIf you could see the love in my eyes\n\nYou should know that I'm on your side\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
