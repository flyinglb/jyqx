// monkey.c ����

inherit NPC;

void create()
{
        set_name("����", ({ "monkey" }) );
        set("gender", "����");
        set("race", "Ұ��");
        set("age", 10);
        set("long", "��ֻ�����������������£����������鲻�á�\n");
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("limbs", ({ "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 8000+random(1000));

        set_temp("apply/attack", 300);
        set_temp("apply/defense", 130);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 100);
        setup();
}
