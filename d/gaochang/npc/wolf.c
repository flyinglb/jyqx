//wolf2.c
inherit NPC;
void create()
{
        set_name("��", ({ "wolf", "lang" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һƥ����ֱ�������۷����̹���ǡ�\n");
        set("attitude", "aggressive");
        set("str", 26);
        set("cor", 30);
        set("limbs", ({ "ͷ��", "����", "�Ȳ�", "β��",}) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 500000);
        set("chat_chance",50);
        set_skill("dodge",300);
		set_skill("unarmed",300);
		set_temp("apply/attack", 25);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence",20);
        setup();
}
