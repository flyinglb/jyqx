// modify by unix
#include <weapon.h>
#include <ansi.h>
#include <login.h>
inherit NPC;
int time=0;
//void init_data ();
void create()
{
	set_name(this_player()->name(), ({"���̨"}));
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
	��������������"+this_player()->name()+"Ϊ��ҵ�һ�ף�\n\n"+
HIW"		<<����>>"NOR
HIW"	����������(music)�������ʹ��(tune music)����\n"+
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n�����ڵȴ�һ��Ů��\n\n�����ڵȴ���Ե�ຣ������\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\nһ����ĬĬ�߿�������\n\nȷ������й������������\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n�úõ�һ�ְ���������ô�������仵\n\n����ı��������Ϻ��ҵ���\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n�ҵ��ķ·����̵��޺޵���\n\n�����ϵİ�������������\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\nһ��������"+this_player()->name()+"��������������ᡣ\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
