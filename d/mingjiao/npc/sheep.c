// sheep.c

inherit NPC;

void create()
{
    set_name("Ұ��", ({ "sheep" }) );
    set("gender", "����");
    set("race", "Ұ��");
    set("age", 2);
    set("long",
        "��ֻҰ���ڵ�ͷ�Բݣ�������Ҳ�����ܡ�\n");
    set("combat_exp", 5000);
    set("shen_type", -1);
    set("attitude", "peaceful");
    set("limbs", ({ "���", "ǰ��", "����" }) );
    set("verbs", ({ "hoof" }) );

    set("water", 200);
    set("food", 200);

    set("apply/attack", 10);
    set("apply/defense", 10);

    setup();
}
