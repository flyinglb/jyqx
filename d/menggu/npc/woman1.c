void create()
{
        set_name("蒙古族妇女", ({ "woman" }) );
        set("gender", "女性" );
        set("age", 40);
        set("long", "一个很健壮的蒙古族中年妇女。\n");
        set("shen", 1000);
        set("combat_exp", 1500);
        set("env/wimpy", 80);
        set("chat_chance_combat", 50 );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "蒙古族妇女看着你笑了起来\n",
                "蒙古族妇女说道：好香的奶茶，要不要来一碗？\n",
                "蒙古族妇女向你努了努嘴，又指了指西边。\n",
		(: random_move :)
        }) );
	carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);
}

