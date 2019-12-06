// shendiao.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name(HIW "神雕" NOR, ({ "shen diao", "diao" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只巨大的雕，它身躯沉重，翅短不能飞翔，但奔跑迅疾，有如骏马。\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "雕头", "雕身", "雕爪", "雕抓", "雕巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 1800000);

        set_temp("apply/attack", 1000);
        set_temp("apply/defense", 2000);
        set_temp("apply/armor", 300);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "神雕向后挪了挪，很是戒备的神情。\n",
                "神雕一声长吼，四下传来阵阵会响。\n",
        }) );
}
