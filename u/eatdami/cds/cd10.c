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
HIY"\nEvery night in my dreams I see you, I feel you\n\nThat is how i know you go on.\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"�ſ�ɤ�ӳ�����\n"+
HIY"\nFar across the distance and spaces between us\n\nYou have come to show you go on.\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"����ĳ��ţ�\n"+
HIY"\nLove can touch us one time and last for a lifetime\n\nAnd never let go till we're gone..\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"����������\n"+
HIY"\nLove was when i loved you one true time i hold to\n\nIn my life we'll always go on.\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"���߸�\n"+
HIY"\nYou're here , there's nothing i fear\n\nAnd i know that my heart will go on.\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
