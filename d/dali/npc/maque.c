// maque.c

inherit NPC;

void create()
{
        set_name("��ȸ", ({ "maque"}));
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻߴߴ������������ȥ��С��ȸ��\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);

        set("chat_chance", 10);
        set("chat_msg", ({
        "��ȸ����ͷ�ϴ��ת���ַɻ����ϡ�\n",
        "��ȸ�����������˼�����\n",
        }) );

        setup();
}
