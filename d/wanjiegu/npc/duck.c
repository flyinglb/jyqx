// duck.c

inherit NPC;

void create()
{
        set_name("ҰѼ", ({ "duck" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻҰѼ��\n");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 50);
        set("combat_exp", 500);

        setup();
}

