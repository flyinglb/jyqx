// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("С��", ({ "seller" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"��λС������Ц���������æ��������ʱ�к������Ŀ��˽�����\n");
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/shaolin/obj/hulu",
		"/d/city/obj/zhubang",
                "/d/village/obj/zhujian",
                "/d/xingxiu/obj/fire",
	}) );
	setup();
        carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
	object ob;
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "С����Ц�Ǻ�˵������λ" + RANK_D->query_respect(ob) + "������Ҫ��ʲô��\n");
	return;
}

