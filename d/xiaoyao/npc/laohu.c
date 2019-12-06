// laofu.c 老虎

inherit NPC;

void create()
{
        set_name("老虎", ({ "laohu", "tiger","hu" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一只斑斓猛虎，雄伟极了。\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "虎头", "虎身", "前爪", "后抓", "尾巴" }) );
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
