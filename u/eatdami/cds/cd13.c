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
������  ���  ��  �����  �������  ���\n
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
	���વ�˵��������Ϊ����ݳ�һ��\n\n"+
HIW"      ���һλ<<�ر����>>����"NOR
HIG"ϣ����Ҷ�һ��ϸ��\n"NOR+
HIW"    ���������(music)�����(tune music)һ�����ٿ�\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIR"С��������\n"+
HIY"\nLove is real Real is love\n\nLove is feeling Feeling love\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"�ſ�ɤ�ӳ�����\n"+
HIY"\nLove is wanting To be love\n\nLove is touch Touch is love\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"����ĳ��ţ�\n"+
HIY"\nLove is reaching Reaching love\n\nLove is asking To be love\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"����������\n"+
HIY"\nLove is you You and me\n\nLove is knowing We can be\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"���߸�\n"+
HIY"\nLove is free Free is love\n\nLove is living Living love\n"NOR);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
