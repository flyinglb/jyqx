// yetu.c Ұ��

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "ye tu", "ye", "hare" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һֻ�ÿɰ���СҰ�á�\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
	ob = new(__DIR__"turou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
