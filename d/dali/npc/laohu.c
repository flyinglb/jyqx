// laofu.c �ϻ�
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("�ϻ�", ({ "laohu", "tiger","hu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ����ͻ�����ΰ���ˡ�\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 50000);
        set("neili",800);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 10000);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "�ϻ��ڿ�Ѳ���ŵ�����������ҳ���\n",
                "�ϻ����쳤Х������ɽ�ȣ���Ҷ��׹��\n",
        }) );
}

