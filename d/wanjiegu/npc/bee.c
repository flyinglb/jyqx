// bee.c
inherit NPC;

void create()
{
        set_name("�۷�", ({ "bee" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ����ɱ�˷䡣\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 50);
        set("combat_exp", 500);
        set("bellicosity", 3000 );

        setup();
}
