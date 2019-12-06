inherit NPC;
void create()
{
        set_name("高则成", ({ "gao zecheng", "gao" }));
        set("title", "昆仑派");
        set("long", 
                "他神志已经不清楚，看来帮不了你什么。\n");
        set("gender", "男性");
        set("age", 29);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 22);
        set("dex", 28);
        set("per", random(15) + 10);
        set("no_xi", 1);
        set("max_qi", 200);
        set("max_jing", 100);
        set("neili", 50);
        set("max_neili", 50);
        set("jiali", 100);
        set("combat_exp", 5000);
        set("shen",0);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);

        create_family("昆仑派", 5, "弟子");

        setup();
        carry_object("/clone/cloth/male1-cloth")->wear();
        
}