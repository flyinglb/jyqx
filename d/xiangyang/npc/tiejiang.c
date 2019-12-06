// tiejiang.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "tiejiang", "smith" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);

	set("gender", "����" );
	set("age", 33);
	set("long", "��λ�������ڶ��������ش���������������ע����������̧��ͷ��΢Ц��һ�¡�\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
	    "/clone/weapon/gangdao",
	    "/clone/weapon/changjian",
	    "/clone/weapon/qimeigun",
	    "/clone/weapon/changbian",
	    "/clone/weapon/gangzhang",
	    "/d/city/npc/obj/tiejia",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

