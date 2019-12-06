inherit NPC;
void create()
{
        set_name("厨师", ({ "chu shi", "chu" }));
        set("title", "昆仑派");
        set("long", 
                "昆仑派的一个厨子，笑眯眯地看着你，看来很和善的样子。\n");
        set("gender", "男性");
        set("age", 34);
        set("attitude", "peaceful");
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 200);
        set("max_jing", 50);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 500);
        set("shen",0);
        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("cuff", 10);
        set_skill("parry", 10);

        create_family("昆仑派", 7, "弟子");
        setup();
        carry_object("/clone/cloth/male1-cloth")->wear();        
}

