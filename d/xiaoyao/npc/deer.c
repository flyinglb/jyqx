// deer.c

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name(YEL"梅花鹿"NOR, ({ "deer", "lu" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一只漂亮的梅花雄鹿。\n");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "鹿头", "鹿身", "前腿", "后腿", "臀部" }) );
        set("verbs", ({ "hoof" }) );

        set("combat_exp", 19000+random(1000));

        set_temp("apply/attack", 350);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 8);
        set_temp("apply/armor", 100);
        setup();
}
