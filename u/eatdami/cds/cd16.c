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
	Ц������˵��������Ϊ����ݳ�һ�׻ưټҵ�����\n\n"+
HIM"		�����롷"NOR
HIW"ϣ�����ϲ��\n"NOR+
HIW"	����������(music)���������(tune music)�ص���\n"
NOR,users());
}
	if(time==3)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIC""
+this_player()->name()+HIW"˻����ɤ�ӳ�����\n"+
HIM"\n�����ֵȵ������費��Ʈ�㣬\n\n�����ٷŵ��������ѱ�����\n\n�׿���ֻ����̵ĳ���������\n\n�ڻ����������ֵ�ͯ�����롣\n"NOR);
	}
	if(time==6)
	{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"����������\n"+
HIR"\n��"HIY"Խ�ǳ�ɽ���������Ц����\n\n"HIR"ѩ"HIY"ҹ��������ĵ�������ʱ�⣬\n\n"HIR"��"HIY"�����Խ���޵���˿������â��\n\n"HIR"��"HIY"���е�ָ�����ʱ��Ѱ�����롣\n"NOR);
	}
	if(time==9)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"����س��ţ�\n"+
HIR"\n��"HIY"��Ӣ�۽���ڣ�\n\n"HIR"��"HIY"��������ǰ����\n\n"HIR"¹"HIY"��ɽ�У���ԯ̨ǰ��������������̡�\n"NOR);
}
	if(time==12)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"����������\n"+
HIR"\nЦ"HIY"̸������������ʮָ�������\n\n"HIR"��"HIY"д���������������ͻ�ƺ�ģ�\n\n"HIR"��"HIY"���ü�Ŀչ���Ļ��������䣬\n\n"HIR"��"HIY"ħ��ɲ�Ƿ�������Ը�������롣\n"NOR);
}
	if(time==15)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"�س������س�����\n"+
HIR"\n��"HIY"�������λ��裬\n\n"HIR"��"HIY"Ѫ�������Գ���\n\n"HIR"ԧ"HIY"��˫�������¾Ž���˭�ͱ��������磿\n"NOR);
}
	if(time==18)
{
	CHANNEL_D->do_channel(this_object(), "music",
HIG""+this_player()->name()+HIW"Ʈ�����ĸ�����\n"+
HIM"\n���롭��\n\n���롭��\n\n"NOR);
	this_object()->set_temp("sing", 0);
	this_player()->set_temp("sing", 0);
destruct(this_object());
}
}
