// shendiao.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name(HIW "���" NOR, ({ "shen diao", "diao" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�޴�ĵ����������أ���̲��ܷ��裬������Ѹ�������翥��\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "��צ", "��ץ", "���" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 1800000);

        set_temp("apply/attack", 1000);
        set_temp("apply/defense", 2000);
        set_temp("apply/armor", 300);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "������Ų��Ų�����ǽ䱸�����顣\n",
                "���һ���������´���������졣\n",
        }) );
}
