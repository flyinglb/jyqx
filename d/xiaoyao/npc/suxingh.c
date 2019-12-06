// suxingh.c
// shilling 97.2

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_book();
int ask_job();

void create()
{
	set_name("苏星河",({"su xinghe","su"}));
	set("gender", "男性" );
	set("nickname", "聪辩老人");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 30);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("no_clean_up",1);

	set("long",
"此人就是号称聪辩老人的苏星河，据说他能言善辩， \n"
"是一个武林中的智者，而他的武功也是无人能知。\n");

	set("combat_exp", 500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
		"秘密地道" :(:ask_me:),
		"秘籍"     :(:ask_book:),
                "job"      :(:ask_job:),
                "工作"     :(:ask_job:),
	]) );

	set("max_qi", 3400);
	set("max_jing", 400);
	set("neili", 3500);
	set("max_neili",3500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
    set_skill("chess",150);
	set_skill("lingboweibu", 150);
	set_skill("beiming-shengong", 150);
	set_skill("ruyi-dao", 150);
	set_skill("liuyang-zhang", 150);
	set_skill("zhemei-shou", 150);
	set_skill("literate", 100);
        set_skill("strike", 150);
        set_skill("hand", 150);

	map_skill("strike", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	

	create_family("逍遥派", 2, "弟子");
	set("title","逍遥派第二代大弟子");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}

int ask_job()
{
        object who = this_player();
        //int pot = (int)(who->query("potential")) - (int)(who->query("learned_points"));

        if(who->query("family/family_name") != "逍遥派") {
        write(name()+"对你说道：我们逍遥派还不至于要您来帮忙，谢谢了您呐。\n");
        return 1;
        }
        if(who->query_temp("job_xiaoyao")) {
        write(name()+"对你说道：你不是还有事做么？先去干完你的活。\n");
        return 1;
        }
        //if(pot >= who->query_int() * 30 ) {
        //write(name()+"上下打量了你一会说道：“现在没什么活可以让你干的。”\n"
        //"你还是在手脚上多下点工夫吧！\n");
        //return 1;
        //}
        if(who->query("combat_exp") > 500000 ) {
        write(name()+"对你说道：这些小事还是让小辈们去做吧。\n");
        return 1;
        }
        who->set_temp("job_xiaoyao",1);//给任务标记
        message_vision(name()+"对$N说道：好吧，你就去问我徒弟要工具去！\n", who);
        return 1;
}

void attempt_apprentice(object ob)
{

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在学问上多下点功夫？");
		return;
	}

	command("say 好吧，我就收下你了，今后要多加努力啊！");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
	object ob;
	mapping fam; 

	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要秘籍就得加入逍遥派。";
	}
	command("sigh");
	return"本派的武功秘籍藏在一个很秘密的地方，我也没去过。";
}
string ask_me()
{
	object ob;
	mapping fam; 

	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要知道密道就得加入逍遥派。";
	}
	command("sigh");
	return"本派的密道在华山之上，很是艰险。你有兴趣可以去看看。";
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "scholar");
}
