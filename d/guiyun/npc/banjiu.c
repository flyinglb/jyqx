// banjiu.c

inherit NPC;

void create()
{
        set_name("���", ({ "ban jiu"}));
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻС��𣚣����ؼ��������¡�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);

        setup();
}
