// tangzi.c

inherit NPC;

void create()
{
	set_name("������", ({ "tangzi shou","shou" }) );
	set("gender", "����");
	set("age", 30);
	set("long",
		"���Ǹ��ھ������֣����û���������һ���������\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "peaceful");

	set("apply/attack", 20);
	set("apply/defense", 20);

	set("chat_chance", 5);
	set("chat_msg", ({
		"������һ����: �ҡ����䡫��ά���������\n",
		(: random_move :)
	}) );

	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	setup();

        carry_object("/d/city/obj/duanjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/jitui");

	add_money("silver", 1);
}
