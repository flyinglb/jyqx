// laojisi.c

inherit NPC;

void create()
{
	set_name("�����ϼ�˾", ({ "lao jisi", "lao", "jisi" }));
	set("gender", "����");
	set("age", random(10) + 60);
	set("str", 25);
	set("dex", 16);
	set("long", "һ��������ļ�˾���������Ĵ��⣬�����Ķ���������ʾ���λ������\n");
	set("combat_exp", 3000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("sword", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object(__DIR__"obj/wdahui")->wear();
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
