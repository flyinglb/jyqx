//mangshe.c

inherit NPC;

void create()
{
	set_name("����", ({ "mang she", "she" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һֻ����ֱ�������ų���о�Ĵ����ߡ�\n");
	set("attitude", "peaceful");

	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 5000);

        set("chat_chance",50);
	set("chat_msg", ({
		"�����߻��������ע�����㣬�����һ�����£�\n",
		"����������һ��Ѫ���ڣ�������ˡ�\n"
	}) );

	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);

	setup();
}

void die()
{
	object ob;
	message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
