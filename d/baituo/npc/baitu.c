//baitu.c
inherit NPC;

void create()
{
        set_name("����", ({ "bai tu", "tu" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻѩ�׵�С���ã��ɰ�֮�¡�\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 200);

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N����һ�ţ�$N���ˡ�\n", this_object());
	ob = new("/d/baituo/obj/turou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
