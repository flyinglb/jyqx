
inherit NPC;
void create()
{
    set_name("�����", ({ "huilang", "lang" }) );
	set("race", "Ұ��");
	set("age", 10);
    set("long", "һͷ�ߴ�Ķ���, �������, ¶����ɭɭ�������\n");
    set("attitude", "aggressive");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
     set("no_die",1);
	set("combat_exp", 2000);
//	set("shen_type", 0);
//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 8);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 4);
	setup();
}
void die()
{
	object ob;
    message_vision("$N��ҵĺ��˼���, �ڵ��ϴ��˼��������������ˡ�\n", this_object());
	ob = new(__DIR__"obj/langpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
