// laofu.c �ϻ�

inherit NPC;

void create()
{
        set_name("�ϻ�", ({ "laohu", "tiger","hu" }) );
        set("race", "Ұ��");
        set("age", 10);
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

        set_temp("apply/attack", 3000);
        set_temp("apply/defense", 2000);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 1000);
        setup();
}
