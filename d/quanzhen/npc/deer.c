// deer.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name(YEL"÷��¹"NOR, ({ "deer", "lu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ��ѱƯ����÷����¹��\n");
        set("attitude", "peace");
        set("shen_type", 1);

        set("limbs", ({ "¹ͷ", "¹��", "ǰ��", "����", "�β�" }) );
        set("verbs", ({ "hoof" }) );

        set("combat_exp", 2000);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 10);

        setup();
}
