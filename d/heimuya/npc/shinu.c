//shinu.c
inherit NPC;
void greeting(object);
void init();
void create()
{
       set_name("��Ů", ({ "shi nu" }) );
	set("gender", "Ů��" );
	set("age", 20);
	set("long", "��Ŀ����,��������,����޲�����������������һ�ѡ�\n");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 20);
	set("per", 27);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");
	setup();
	carry_object("/d/heimuya/npc/obj/cloth")->wear();
	 add_money("silver",10);
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
