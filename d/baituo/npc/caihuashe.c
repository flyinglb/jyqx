// NPC /d/npc/caihuashe.c
inherit NPC;

void create()
{
        set_name("�˻���", ({ "caihua she", "she" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�����ĵĲ˻��ߣ�ͷ������Բ�Ρ�\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 100+random(50));

        set_temp("apply/attack", 7);
        set_temp("apply/damage", 4);
	set_temp("apply/defence",6);
	set_temp("apply/armor",5);

	setup();
}

void die()
{
	object ob;
	message_vision("$N�鴤���£�$N���ˡ�\n", this_object());
	ob = new(__DIR__"obj/sherou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
