// wolf.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("Ұ��", ({ "wolf", "yelang", "lang" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ���е�Ұ�ǣ������ŵĴ�����¶�ż��������\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 20000);
        set_temp("apply/attack", 2000);
        set_temp("apply/defense", 3000);
        set_temp("apply/armor", 800);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "Ұ��������β�ͣ�ͻȻ̧ͷ�����㷢��һ�������ĳ�����\n",
                "Ұ�����������ĵ��۹���������飬Ѫ��޿�������Ź����ӡ�\n",
        }) );
}

