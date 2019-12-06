// by wind
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��������", ({ "flower girl","girl"}) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long", "һ����ò������С���\n");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
        set("vendor_goods", ({
                "/d/city2/obj/flower/flower",
                "/d/city2/obj/flower/guihua",
                "/d/city2/obj/flower/hua",
                "/d/city2/obj/flower/juhua",
                "/d/city2/obj/flower/rose",
                "/d/city2/obj/flower/rose999",
                "/d/city2/obj/flower/seed",
        }) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

        add_action("do_buy", "buy");
        add_action("do_list", "list");

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	     say("��������˵������λ" + RANK_D->query_respect(ob)
	     + "����һ�仨�ɡ�\n");
	return;
}
