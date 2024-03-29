inherit NPC;
inherit F_DEALER;
void create()
{
        set_name(YEL "金湘玉" NOR, ({ "jin xiangyu","jin", "xiangyu" }));
        set("title", "龙门客栈老板娘");
        set("shen_type", 0);
        set("gender", "女性");
    set("per",34);
        set("long",
                "金湘玉是黄土高原一带有名的大美人。一些达官贵人，江湖浪子常常在这里歇息，\n"
                "所以她对这一带的一举一动都了如指掌。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "生意" : "这个么……。\n",
        ]));
        
        set("vendor_goods", ({
             "/d/gaochang/npc/obj/hulu.c",
             "/d/xingxiu/npc/obj/fire",
                __DIR__"obj/dogrou",
        }));
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
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
void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("金湘玉笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
                        "，快请进来喝碗酒。\n");
                break;
        case 1 :
                say("金湘玉说道：哟！这位" + RANK_D->query_respect(ob) + 
                        "您来了啊！本店有刚出窑的好酒。\n");
                break;
        }
}
