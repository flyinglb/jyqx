// lion.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("��ʨ", ({ "lion", "xiongshi", "shi" }) );
        set("race", "Ұ��");
        set("age", 15);
        set("long", "һֻ�ý�����ʨ��ʮ�����硣\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "ʨͷ", "ʨ��", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 40000);
        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 800);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "��ʨһ���������´���������졣\n",
                "��ʨ����һ�ţ��͵�һԾ�������ǰ��\n",
        }) );
}

