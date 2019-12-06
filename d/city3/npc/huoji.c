// huoji.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ҩ����", ({ "yaodian huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����ģ������ʵʵ�������ˡ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
//              "/clone/misc/hedinghong",
//              "/clone/misc/bicanfeng",
//              "/clone/misc/kongquedan",
                "/d/city3/npc/obj/jingdan",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
