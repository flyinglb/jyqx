// Jay 5/23/96
inherit NPC;
void create()
{
        set_name("��", ({ "sun", "ying" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("dex", 1000);
        set("long", "һֻ����Сӥ��\n");
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 13000);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);
        set("chat_chance", 10);
        set("chat_msg", ({
        "����ŷ���������س�Х�˼�����\n",       
                  "�������з��Ϸ��¡�\n",
        (: random_move :)
        }) );
        setup();
}
