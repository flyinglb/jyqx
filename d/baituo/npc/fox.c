// fox.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("����", ({ "fox", "huli", "hu" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ���ɳ��Եĺ��ꡣ\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 10000);

        set_temp("apply/attack", 1000);
        set_temp("apply/defense", 2000);
        set_temp("apply/armor", 300);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "�������Ų��Ų�����ǽ䱸�����顣\n",
                "������Ŷ��ɵ��۹���㿴��ȫ��һ���ܽ��ŵ�ģ����\n",
        }) );
}

