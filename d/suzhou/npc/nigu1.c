// nigu1.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("���", ({ "ni gu", "ni", "gu" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("long","��λ����������̵��ϣ�˫���������������������дʡ� \n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "���˵������λ" + RANK_D->query_respect(ob) + "����л������Ը���汣�ӡ�\n");
	return;
}

