// Jay 5/23/96

inherit NPC;

void create()
{
        set_name("ͺӥ", ({ "eagle" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ��ɫ��ͺӥ��ͺͷ���𣬺óԸ�ʬ�����������Ἣ�ˡ�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 3000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 10);

        setup();
}
