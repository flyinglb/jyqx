// ding.c 丁春秋

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_du1();
string ask_du2();

void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("nickname", "星宿老怪");
	set("long", 
		"他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
		"可是他看起来形貌清奇，仙风道骨。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

	set_skill("force", 150);
	set_skill("huagong-dafa", 180);
	set_skill("throwing", 150);
	set_skill("feixing-shu", 150);
	set_skill("dodge", 150);
	set_skill("zhaixinggong", 180);
	set_skill("strike", 150);
	set_skill("chousui-zhang", 180);
	set_skill("claw", 150);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("parry", 150);
	set_skill("staff", 150);
	set_skill("poison", 150);
	set_skill("tianshan-zhang", 180);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("book_count", 1);
	set("zhen_count", 1);
	set("san_count", 1);

	set("inquiry", ([
		"毒经" : (: ask_me :),
		"星宿毒经" : (: ask_me :),
		"碧磷针" : (: ask_du1 :),
		"三笑逍遥散" : (: ask_du2 :),
		"逍遥三笑散" : (: ask_du2 :),
	]));

	create_family("星宿派", 1, "开山祖师");
	set("class", "taoist");

	setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }
        if ((int)me->query("combat_exp") < 10000) {
                command("say 你这点微末道行如何能学到老仙的神妙功夫。");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一副等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说老仙什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
         || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

// 星宿老仙，德配天地，威震寰宇，古今无比

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "好吧，这本「星宿毒经」你拿回去好好钻研。";
}
string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<50)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("zhen_count") < 1)
		return "你来晚了，碧磷针都发完了。";
	add("zhen_count", -1);
	ob = new("/d/xingxiu/obj/bilinzhen");
	ob->move(this_player());
	return "好吧，那你就先用这些针吧。";
}
string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("san_count") < 1)
		return "你来晚了，现在没什么剩的了。";
	add("san_count", -1);
	ob = new("/d/xingxiu/obj/sanxiaosan");
	ob->move(this_player());
	return "好吧，这包毒药你拿回去善加利用吧。";
}
