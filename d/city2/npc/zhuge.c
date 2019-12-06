// zhuge.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
int do_play(string arg);

void create()
{
	set_name("�����̫", ({ "zhuge" }));
	set("gender", "Ů��");
	set("age", 54);
	set("str", 25);
	set("dex", 20);
	set("long", "����һλ��̫̫������ֱ��ǰ������������\n");
	set("combat_exp", 200000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("neili", 1500); 
	set("max_neili", 1500);
	set("jiali", 100);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
::init();
add_action("do_play","play");
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
message_vision(HIC "�����̫��$NЦ��Ц��˵��:�٣�С�ӣ��ɱ�������MUD��ץס������ÿ��ġ�\n" NOR,ob);		
command("grin");
return;
}


int do_play(string arg)
{
if(!arg||arg!="mud")
return notify_fail("������ʲô��");
this_object()->kill_ob(this_player());
this_player()->fight_ob(this_object());
return 1;
}

