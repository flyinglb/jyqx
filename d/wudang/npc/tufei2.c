// tufei2.c

inherit NPC;

void create()
{
	set_name("����", ({ "tufei","bandit","fei" }) );
	set("gender", "����");
	set("age", 20);
	set("long",
		"��һ��������⪬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 5000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 10);
	set("apply/defense", 10);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"����һ����: ��ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n",
//	}) );

	set_skill("unarmed", 25);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}
