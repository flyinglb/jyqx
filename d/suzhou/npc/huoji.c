// huoji. ҩ�̻��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "������������С���ӡ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
//		"/clone/misc/zhujingchan",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
