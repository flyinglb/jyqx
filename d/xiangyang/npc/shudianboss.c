// shudianboss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����ϰ�", ({ "shudian laoban", "boss" }) );
	set("gender", "����" );
	set("age", 62);
	set("long", "һ���ú�����һ���;��ÿ��׵����̡�\n");
	set("combat_exp", 3000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/book/parry_book",
		"/clone/book/blade_book1",
	}) );
	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

