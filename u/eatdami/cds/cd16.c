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
	笑嘻嘻地说：下面我为大家演唱一首黄百家的新作\n\n"+
HIM"		《梦想》"NOR
HIW"希望大家喜欢\n"NOR+
HIW"	想听的请用(music)否则可以用(tune music)关掉。\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIW"嘶哑着嗓子唱道：\n"+
HIM"\n等了又等的乌龙茶不再飘香，\n\n放下再放的麦当劳早已冰凉，\n\n抛开这钢混凝固的尘世重量，\n\n融化到单调文字的童真梦想。\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"纵声唱道：\n"+
HIR"\n飞"HIY"越那崇山峻岭的你我笑骂疯狂，\n\n"HIR"雪"HIY"夜里快意恩仇的刀剑纵情时光，\n\n"HIR"连"HIY"接这跨越五洲的纤丝跳动锋芒，\n\n"HIR"天"HIY"地中弹指方寸的时空寻回梦想。\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"温柔地唱着：\n"+
HIR"\n射"HIY"雕英雄今何在，\n\n"HIR"白"HIY"马西风问前方。\n\n"HIR"鹿"HIY"鼎山中，轩辕台前，东西永隔如参商。\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"继续唱道：\n"+
HIR"\n笑"HIY"谈着轻松跳动的十指弹拨激扬，\n\n"HIR"书"HIY"写出剑气冲天的六脉突破洪荒，\n\n"HIR"神"HIY"情间眉颦目展的心怀再述情殇，\n\n"HIR"侠"HIY"魔道刹那芳华的夙愿还回梦想。\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"回肠荡气地唱道：\n"+
HIR"\n倚"HIY"天屠龙任回翔，\n\n"HIR"碧"HIY"血丹心论衷肠。\n\n"HIR"鸳"HIY"鸯双刀，独孤九剑，谁送冰舸来仙乡？\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"飘出最后的歌声：\n"+
HIM"\n梦想……\n\n梦想……\n\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
