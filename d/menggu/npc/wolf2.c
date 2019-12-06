//wolf2.c
inherit NPC;
void create()
{
        set_name("野狼", ({ "wolf", "yelang" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一匹昂首直立，两眼放着绿光的狼。\n");
        set("attitude", "aggressive");
        set("str", 26);
        set("cor", 30);
        set("limbs", ({ "头部", "身体", "腿部", "尾巴",}) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 500000);
        set("chat_chance",50);
        set_skill("dodge",200);
	set_skill("unarmed",200);
	set_temp("apply/attack", 25);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence",20);
	set("chat_msg", ({
		"\n野狼用一双贼绿的眼睛盯着你，血盆的口已经张开。\n"
		(: random_move :)
	}) );
        setup();
}
