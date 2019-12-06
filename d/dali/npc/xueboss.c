// xueboss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("Ѧ�ϰ�", ({ "xue laoban", "xue" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"����һ�������ϵ��������ˣ�һ˫�������۾���ͣ�Ĵ������㡣\n");
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/shoes",
		__DIR__"obj/doupeng",
                __DIR__"obj/guazi",
                __DIR__"obj/kenao",
                __DIR__"obj/qun",
	}) );
	setup();
        carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

