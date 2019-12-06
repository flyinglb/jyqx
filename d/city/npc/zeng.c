// zeng.c
// modified by wind

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "zeng rou", "zeng", "rou" }));
	set("shen_type", 1);

	set("gender", "Ů��");
	set("age", 16);
	set("per", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("str", 25);
	set("long",
"����Τ��ү��֪���ڼ�����С檣������￪�������̣���Щ��֪��
�������·�������˵�Ƕ���Τ��ү�ӹ���Ū�����Ľ�Ʒ������ô˵��
����������\n");
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"cloth/belt",
		__DIR__"cloth/boots",
		__DIR__"cloth/bu-shoes",
		__DIR__"cloth/cloth",
		__DIR__"cloth/color-dress",
		__DIR__"cloth/feature",
		__DIR__"cloth/fu-cloth",
		__DIR__"cloth/gui-dress",
		__DIR__"cloth/hat",
		__DIR__"cloth/jade-belt",
		__DIR__"cloth/liu-dress",
		__DIR__"cloth/marry-dress",
		__DIR__"cloth/mini-dress",
		__DIR__"cloth/moon-dress",
		__DIR__"cloth/pink-dress",
		__DIR__"cloth/qi-dress",
		__DIR__"cloth/red-dress",
		__DIR__"cloth/scarf",
		__DIR__"cloth/sha-dress",
		__DIR__"cloth/shoes",
		__DIR__"cloth/xian-cloth",
		__DIR__"cloth/xiu-cloth",
		__DIR__"cloth/xiu-scarf",
		__DIR__"cloth/yan-dress",
		__DIR__"cloth/zi-dress",
	}));
	
	setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
