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
HIW"		<<������>>  ԭ�������»�\n"NOR+
HIW"	����������(music)���������(tune music)�ص���\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n����һ��Զ�����ǵ���ˮ�������������Ѽ�����\n\n����������¶����ҿ�������
	����ů�����������\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n���Ļ����������ԣ�����\n\n�����ɫ����������ۿ������ʱ����\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n����̫����ˣ��ҹ��̶���ʧȥ�˷���\n\n�������Ƿ�����ϡ�ĵƹ�\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\nû����ѡ�����������ˣ���\n\n������ҹ�գ�����ʹ�Ҳ��ڼ�į������\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"
\n����һ��Զ�����ǵ���ˮ�������������Ѽ�����\n\n����������¶����ҿ���\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIY"\n������ů�����������\n\n��Ҫ�ٺ������森������\n");
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
