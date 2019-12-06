inherit NPC;

void create()
{
        set_name("野马", ({ "horse", "ye ma" }));
        set("long","一只未经驯化的长鬃野马。\n");
        set("race", "野兽");
        set("age", 1);
        set("int", 30);
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 500);
        set("max_jing", 500);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("chat_chance",50);
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "腹部", "尾巴","后蹄","前蹄" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

	set("chat_msg", ({
		"\n野马稀溜溜嘶鸣了一声。\n"
		"\n野马突然向前冲去，只留下一串蹄声。\n"
		(: random_move :)
	}) );
        setup();
}

