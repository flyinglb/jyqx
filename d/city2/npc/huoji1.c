// huoji. ���׳����

inherit NPC;

void create()
{
	set_name("���׳����", ({ "huo ji", "huo","ji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "��ʮ��ǿ׳������ȥ�Ἰ���书��\n");
	set("combat_exp", 10000);
	set_skill("unarmed", 30);
	set_skill("blade", 60);
	set_skill("dodge", 30);
	set_skill("parry", 50);
	set("attitude", "friendly");
	setup();
        carry_object("/d/city2/obj/tudao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}

