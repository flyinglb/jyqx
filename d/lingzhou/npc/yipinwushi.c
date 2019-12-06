// yipinwushi.c

inherit NPC;

void create()
{
	set_name("һƷ����ʿ", ({ "wu shi", "shi" }));
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "����һƷ�õĻ�Ժ��ʿ�������ּף���ִ�䵶��\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 10);

	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
	carry_object("/d/xingxiu/obj/wandao")->wield();
//	carry_object("/clone/weapon/gangdao")->wield();
}

