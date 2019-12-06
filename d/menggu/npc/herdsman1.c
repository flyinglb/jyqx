inherit NPC;

void create()
{
        set_name("牧马人", ({ "muma ren", "ren", "heardsman" }));
        set("gender", "男性");
        set("age", 30 + random(10));

        set("long", "一个蒙古大汉，手里拿着马鞭，赶着一群马。\n");

        set("attitude", "friendly");

        set("combat_exp", 5000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("whip", 20);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("inquiry", ([
                "蒙古" : "这里就是蒙古草原。\n",
                "蒙古草原" : "草原深处居住着成吉思汗，他是我们民族的骄傲。\n",
                "草原" : "草原深处居住着成吉思汗，他是我们民族的骄傲。\n",
                "成吉思汗" : "你能在草原上不迷路就能找到。\n",
        ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		"牧马大汉开心地说道：有大汗在，这草原上再没有谁敢欺负我们蒙古人。\n",
		"牧马大汉兴奋地甩了甩马鞭。\n",
        }) );

        carry_object(__DIR__"obj/mcloth")->wear();
        carry_object(__DIR__"obj/bian")->wield();
}


