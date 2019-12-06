// bing.c

inherit NPC;

void create()
{
	set_name("ʿ��", ({ "shi bing", "bing" }));
	set("age", 32);
	set("gender", "����");
	set("long", "����һ�������������ʿ�������Ž��£���ִ�ֵ���˫Ŀ���⾼
���������Ѳ�������ܵ����Ρ�\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
