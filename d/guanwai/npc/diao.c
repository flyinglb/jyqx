//  /guanwai/npc/diao.c

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name(HIY"���"NOR, ({ "diao"}));
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ������������֦�����ӳ��졣\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 50);

        setup();
}
