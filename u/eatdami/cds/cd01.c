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
HIW"		<<����ң>>"NOR
HIW"ϣ�����ϲ��\n"NOR+
HIW"	����������(music)���������(tune music)�ص���\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIR"С��������\n"+
HIY"\n���ұ�Ҳ�� ���һ�Ҳ��\n\n�޲����㶼�����ˣ�����\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"�ſ�ɤ�ӳ�����\n"+
HIY"\n���ҿ�Ҳ�� ������Ҳ��\n\n���ƮƮ�������ң������\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"����ĳ��ţ�\n"+
HIY"\nӢ�۲��³���̫��������־����߶��Ƕ���Ҫ\n\n��Ϊһ��Ե��������\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"����������\n"+
HIY"\nһ��һ���벶������\n\n�మ�����춼������ ��Թ����������ͷ��\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"���߸�\n"+
HIY"
\n�а����Ĳ��ܻ�� ��������������ĺã���\n\n������Ҳ�� ����˯Ҳ��\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIR"���ų�����\n"+
HIY"\n���Ҷ�Ҳ�ã����Ҵ�Ҳ��\n\n���ƮƮ�����������ң������\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
