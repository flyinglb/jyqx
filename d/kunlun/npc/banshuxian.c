inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("班淑娴", ({ "ban shuxian", "ban", "shuxian"}) );
        set("title", HIG "昆仑派掌门夫人" NOR);
        set("gender", "女性");
        set("age", 38);
        set("long",
         "她就是昆仑派掌门何太冲的妻子。她脾气粗暴，气量狭窄
昆仑上下都对她十分畏惧。她快四十岁了，仍是风韵尤存。\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",1000);
        set("max_jingli",1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali",200);
        set("rank_info/respect", "掌门夫人");        
        set("combat_exp",1000000);
 
	set_skill("force", 190);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("xuantian-force", 180);
	set_skill("sword", 200);
	set_skill("literate",100);
	set_skill("zhengliangyi-sword", 190);
	set_skill("yaoming-dodge", 200);
	set_skill("sanyin-unarmed",170);
	set_skill("unarmed",200);
           
	map_skill("dodge", "yaoming-dodge");
	map_skill("force", "xuantian-force");
	map_skill("parry", "zhengliangyi-sword");
	map_skill("sword", "zhengliangyi-sword");
	map_skill("unarmed","sanyin-unarmed");   
	prepare_skill("unarmed","sanyin-unarmed"); 

	create_family("昆仑派", 4, "掌门夫人");
	setup();
	carry_object("/clone/cloth/female4-cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "女性" )
	{        
		command("say 男人都不是好东西，给我滚。");
		return;
	}

	if ((int)ob->query_skill("xuantian-force", 1) < 50) 
	{
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练内功心法？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
	ob->set("title", HIG "昆仑派第五代弟子" NOR);
}
