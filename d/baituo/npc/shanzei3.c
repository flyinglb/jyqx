//shanzei3.c
inherit NPC;

void create()
{
	set_name("ɽ��ͷ", ({ "shanzei tou","tou" }) );
	set("gender", "����" );
	set("age", 29);
	set("long", "���Ǹ���³��ɽ��ͷ��\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 24);
	set("int", 23);
	set("con", 24);
	set("dex", 23);

	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 30000+random(5000));
	set("score", 2000);
	setup();
	add_money("silver", 11);
	carry_object("/d/baituo/obj/dadao")->wield();
}

