// huoji. ҩ�̻��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "��ʮ��ǿ׳������ȥ�Ἰ���书����ҩ�������ƺ������ں���\n");
	set("combat_exp", 15000);
	set("attitude", "friendly");
	set("vendor_goods", ({
                "/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/d/city2/obj/gaoyao",
	}));
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
