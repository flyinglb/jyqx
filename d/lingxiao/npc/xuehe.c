//LUCAS 2000-6-18
// xuehe.c

inherit NPC;
#include <ansi.h>;
void create()
{
        set_name(HIW"ѩ��"NOR, ({ "xue he", "he"}));
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻȫ���׵�ѩ�ף��Ǵ�ѩɽ���ز���\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 7);
        set_temp("apply/armor", 7);

        setup();
}

