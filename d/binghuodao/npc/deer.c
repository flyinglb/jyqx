// monkey.c

inherit NPC;

void create()
{
    set_name("÷��¹", ({ "deer" }) );
    set("gender", "����");
    set("race", "Ұ��");
    set("age", 5);
    set("long",
        "¹���еس��Ųݡ�\n");
    set("combat_exp", 500);
    set("shen_type", -1);
    set("attitude", "peaceful");
    set("limbs", ({ "ͷ", "ǰ��", "����", "β��" }) );
    set("verbs", ({ "bite", "claw" }) );

    set("water", 200);
    set("food", 200);

    set("apply/attack", 10);
    set("apply/defense", 10);

    /* set("chat_chance", 10);
    set("chat_msg", ({
        "���ӳ������������ߴߴ����һ���ҽ�......!\n",
        "���Ӻ�Ȼ���˹�����һ��������ǰצһ��ժ����Ĳ�ñ!\n",
        "���Ӻ��һ��һ�����������������������������һ����!\n",
    }) );  

    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20); */

    setup();
}

