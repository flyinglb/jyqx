inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
void create()
{
        set_name(MAG "霍青桐" NOR, ({"huo qingtong", "huo" }));
        set("title", HIW "翠羽"YEL"黄衫" NOR);
        set("shen_type", 5);
        set("gender", "女性");
        set("per",48);
        set("long",
                "她就是回疆部落中人称“翠羽黄衫”霍青桐。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "陈家骆" : "sigh，还是不要提了。\n",
        ]));
        set("neili", 200);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen", 0);
        set("combat_exp", 12500);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("sword",50);
	    set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
         carry_object(__DIR__"obj/duanjian")->wield();
         carry_object(__DIR__"obj/ycloth")->wear();
}
/*
void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
// void greeting(object ob)
// {
//        if (!ob || environment(ob) != environment())
//               return;
//        switch(random(2)) {
//        case 0 :
//                say("金湘玉笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
//                        "，快请进来喝碗酒。\n");
//                break;
//        case 1 :
//                say("金湘玉说道：哟！这位" + RANK_D->query_respect(ob) + 
//                        "您来了啊！本店有刚出窑的好酒。\n");
//                break;
//        }
// }
*/
