// modify by unix
#include <weapon.h>
#include <ansi.h>
#include <login.h>
inherit NPC;
int time=0;
void create()
{
	set_name(this_player()->name(),({"cd-3"}));
	set("long", @LONG
������  ���  ��  �����  �������  ���\n
ԭ����������          ������"+this_player()->name()+"\n\n",users());
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
	this_ob