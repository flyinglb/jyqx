// shihou.c 狮吼子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("狮吼子", ({ "shihou zi", "shihou" }));
	set("nickname", "星宿派二师兄");
	set("long", 
		"他就是丁春秋的二弟子狮吼子。\n"
		"他三十多岁，狮鼻阔口，一望而知不是中土人士。\n");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 30000);

	set_skill("force", 60);
	set_skill("huagong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 60);
	set_skill("strike", 70);
	set_skill("chousui-zhang", 40);
	set_skill("claw", 70);
	set_skill("sanyin-wugongzhao", 40);
	set_skill("parry", 60);
	set_skill("poison", 60);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 50);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	create_family("星宿派", 2, "弟子");

	setup();
  	//carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
