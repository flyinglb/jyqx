// zhang.c 张三丰

inherit NPC;
inherit F_MASTER;
string inquiry_book();

void create()
{
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "邋遢真人");
	set("long", 
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	set_skill("force", 250);
	set_skill("taiji-shengong", 250);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("liangyi-jian", 200);
	set_skill("wudang-jian", 200);
	set_skill("taoism",250);
	set_skill("taiji-dao",150);
	set_skill("blade",200);
	set_skill("literate", 180);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");

	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");
	set("inquiry" , ([
	"黄百家" : (: inquiry_book :),
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

string inquiry_book()
{
	object me=this_player();
	object ob;

	if (present("changquan_book",me))
		return "张三丰皱了皱眉说道：书已经给你了，不要贪心！\n";
	else
	{
		ob=new("/clone/book/quanpu2");
		ob->move(me);
 		return "张三丰笑道：很好，这本书就是你的了！\n";
	}
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
         if ((int)ob->query("guarded") < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "想入我武当门下，你还需要多多努力尽心才对。");
                return;
        }
	if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
    if ((int)ob->query_skill("taoism", 1) < 80)
    {
        command("say 我武当派乃道家武功，高深的武功离不开道学心法。");
        command("say " + RANK_D->query_respect(ob) +
            "是否还应该多读读道德经？");
        return;
    }
	if ((int)ob->query("shen") < 2000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 我武当派武功全从道藏悟出。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}
