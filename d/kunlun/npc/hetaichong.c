inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
	{
	set_name("何太冲", ({ "he taichong","he"}));
	set("age", 47);
	set("combat_exp", 900000);
	set("title",HIG"昆仑派掌门人"NOR);
	set("gender","男性");
//	set("attitude","taoism");//?
	set("str", 25);
	set("dex", 30);
	set("con", 30);
	set("int", 28);

	set("max_jingli",1000);
	set("jingli",1000);
	set("jiali",200);
	set("max_neili",3000);
	set("neili",3000);
	set("eff_jing",800);
	set("jing",800);
	set("eff_qi",2500);
	set("qi",2500);

	set_skill("force", 200);
	set_skill("sword", 200);
	set_skill("dodge", 190);
	set_skill("parry", 190);
	set_skill("unarmed",150);
	set_skill("literate",120);
	set_skill("xuantian-force", 180);
	set_skill("zhengliangyi-sword", 180);
	set_skill("yaoming-dodge", 180);
	set_skill("sanyin-unarmed",150);

	map_skill("dodge", "yaoming-dodge");
	map_skill("force", "xuantian-force");
	map_skill("parry", "zhengliangyi-sword");
	map_skill("sword", "zhengliangyi-sword");
	map_skill("unarmed","sanyin-unarmed");   
	prepare_skill("unarmed","sanyin-unarmed"); 

	create_family("昆仑派",4, "昆仑派掌门人");
	set("chat_chance", 15);
	set("chat_msg", ({
	"何太冲说道：想当年创派祖师昆仑三圣，打便西域无敌手，创下这昆仑一派，而今……，唉！  \n",
	"何太冲叹道：谁能找到名医治好五姑的病，我立他为掌门弟子。 \n",
	"何太冲恶狠狠地说：这些没用的弟子，从哪里找了这些庸医来。 \n",
	}) );

setup();
	carry_object("/clone/cloth/male6-cloth")->wear();
	carry_object(__DIR__"obj/shansword")->wield();

}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{        
		command("say 你还是去找我夫人拜师吧。");
		return;
	}
	if (ob->query_skill("xuantian-force",1) <= 50)
	{
	command("say 你的内功修为不够？");
	return;
	}
	message_vision("何太冲拍拍$N的头，微微点了点头。\n",ob);
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
	ob->set("class", "swordsman");
	ob->set("title", HIG "昆仑派第五代弟子" NOR);

	return;
}


