// yu.c 俞莲舟

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("俞莲舟", ({ "yu lianzhou", "yu" }));
	set("nickname", "武当二侠");
	set("long", 
		"他就是张三丰的二弟子俞莲舟。\n"
		"他今年五十岁，身材魁梧，气度凝重。\n"
		"虽在武当七侠中排名第二，功夫却是最精。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 80000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 110);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 80);
	set_skill("liangyi-jian", 80);
	set_skill("taoism", 80);
//	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: exert_function, "recover" :),
	}) );

	create_family("武当派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if ((int)ob->query("guarded") < 15) {
                command("say " + RANK_D->query_respect(ob) +
                        "想入我武当门下，你还需要多多努力尽心才对。");
                return;
        }

        if ((int)ob->query_skill("taiji-shengong", 1) < 40) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
	if ((int)ob->query("shen") < 100) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say " + RANK_D->query_respect(ob) + "若能做出" +
			"几件侠义之事，我一定收你。");
		return;
	}
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
		"我辈中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));
}
