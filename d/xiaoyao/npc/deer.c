// deer.c

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name(YEL"÷��¹"NOR, ({ "deer", "lu" }) );
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һֻƯ����÷����¹��\n");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "¹ͷ", "¹��", "ǰ��", "����", "�β�" }) );
        set("verbs", ({ "hoof" }) );

        set("combat_exp", 19000+random(1000));

        set_temp("apply/attack", 350);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 8);
        set_temp("apply/armor", 100);
        setup();
}
