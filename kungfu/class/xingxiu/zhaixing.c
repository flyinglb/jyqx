// zhaixing.c 摘星子

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_book();

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "星宿派大师兄");
	set("long", 
		"他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
		"他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 40000);

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("throwing", 70);
	set_skill("feixing-shu", 80);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 80);
	set_skill("chousui-zhang", 80);
	set_skill("claw", 80);
	set_skill("sanyin-wugongzhao", 80);
	set_skill("parry", 70);
	set_skill("poison", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"炼心弹"    : (: ask_me :),
		"秘籍"      : (: ask_book :),
		"天山器法"  : (: ask_book :),
	]));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("dan_count") < 1)
		return "你来晚了，没有练心弹了。";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "这些练心弹够你用的了吧。";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，现在没什么剩的了。";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "好吧，这本书你拿回去好好看看吧。";
}
