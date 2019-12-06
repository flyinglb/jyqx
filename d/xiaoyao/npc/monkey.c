// monkey.c 猴子

inherit NPC;

void create()
{
        set_name("猴子", ({ "monkey" }) );
        set("gender", "雄性");
        set("race", "野兽");
        set("age", 10);
        set("long", "这只猴子在树间跳上跳下，他好象心情不好。\n");
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("limbs", ({ "猴嘴", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 8000+random(1000));

        set_temp("apply/attack", 300);
        set_temp("apply/defense", 130);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 100);
        setup();
}
