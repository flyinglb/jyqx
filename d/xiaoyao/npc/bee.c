// bee.c ����

inherit NPC;

void create()
{
        set_name("����", ({ "dufeng", "bee" }) );
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һֻɫ�ʰ�쵴��Ұ�䣬�����������ǡ�\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "����","����","���","β��" }) );
        set("verbs", ({ "bite", "sting" }) );

        set("combat_exp", 4000+random(1000));

        set_temp("apply/attack", 200);
        set_temp("apply/attack", 80);
        set_temp("apply/damage", 5);
        set_temp("apply/armor", 50);
        setup();
}
