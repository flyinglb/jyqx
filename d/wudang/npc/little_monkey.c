// little_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "little monkey", "monkey"}) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 1);
	set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n");
        set("limbs", ({ "猴嘴", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");

        set("water", 200);
        set("food", 200);

        set("chat_chance", 10);
        set("chat_msg", ({
                "小猴子忽然跳了过来，一个倒勾，前爪一伸摘了你的草帽!\n",
                "小猴子轰的一声一起从这株树跳到那株树，把你吓了一大跳!\n",
        }) );


        setup();
}
