// laohu.c

inherit NPC;

void create()
{
        set_name("�ϻ�", ({ "lao hu", "hu" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ���͵Ĵ��ϻ���\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);

      	set("chat_chance", 6);
      	set("chat_msg", ({
              (: random_move :),
      	}) );
	set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);

        setup();
}

void init()
{
  	object me;

  	me=this_player();
	if (interactive(me)) kill_ob(me);
}
 void die()
{
       object ob;
       message_vision("$N�Һ�һ�������ˣ�\n", this_object());
        ob = new(__DIR__"obj/hupi");
       ob->move(environment(this_object()));
       destruct(this_object());
}

