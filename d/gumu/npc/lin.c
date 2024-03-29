// lin.c 林朝英
// modified by wind

#include <ansi.h>

inherit NPC;

string ask_yunv();

void create()
{
	set_name("林朝英", ({"lin chaoying", "lin"}));
	set("gender", "女性");
	set("age", 42);
	set("long", 
		"她就是古墓派的开山祖师林朝英，虽然已经是四十许人，望之却\n"
                "还如同三十出头。当年她与全真教主王重阳本是一对痴心爱侣，\n"
                "只可惜有缘无份，只得独自在这古墓上幽居。\n");
	set("attitude", "friendly");
	
	set("str", 37);
	set("int", 42);
	set("con", 45);
	set("dex", 42);

        set("chat_chance_combat", 6);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
	set("chat_chance", 1);
	set("chat_msg", ({
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
	}));

	set("qi", 6000);
	set("max_qi", 6000);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);
	
	set("combat_exp", 2000000);
	set("score", 0);
	 
	set_skill("force", 220);
	set_skill("yunv-xinfa", 200);    //玉女心法
	set_skill("sword", 200);             
	set_skill("yunv-jian", 200);     //玉女剑
	set_skill("quanzhen-jian",150);  //全真剑
	set_skill("dodge", 200);
	set_skill("yunv-shenfa", 220);   //玉女身法
	set_skill("parry", 200);
	set_skill("unarmed",180);
	set_skill("meinv-quan", 150);    //美女拳法
	set_skill("literate",150);
	set_skill("taoism",140);
	
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("古墓派", 1, "开山祖师");

	set("book_count",1);
        set("inquiry", ([
		"王重阳" :  "大胆后辈小子，也敢直呼重阳祖师之名？\n",
                "重阳祖师" : "重阳是全真教的掌教，自号“活死人”。\n",
		"古墓派" :  "是啊，这里就是我一手创下的古墓派\n",
		"玉女心经" : (: ask_yunv :),
        ]) );

	setup();
	
        carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/qingyi")->wear();

}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30) {
        	command("say 我古墓派的功夫最讲一个悟字，你的资质不够。");
		return;
    	}
    	if ((int)ob->query_skill("yunv-xinfa",1) < 70 ) {
        	command("say 你的玉女心法火候不足,难以领略更高深的武功。");
		return;
    	}
	command("say 好吧，看你也是性情中人，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

string ask_yunv()
{
        mapping fam; 
        object ob;
	int lvl_yunv;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "古墓派")
                return RANK_D->query_respect(this_player()) + 
                "与本派毫无瓜葛，何以问起本派的心经？";
	if (!(lvl_yunv = this_player()->query_skill("yunv-xinfa",1))
	    || lvl_yunv < 55)
		return RANK_D->query_respect(this_player()) +
                "的玉女心法火候不足，我不能将玉女心经交给你";
        if (query("book_count") < 1)
                return "你来晚了，本派的玉女心经已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing2");
        ob->move(this_player());
        return "好吧，这本「玉女心经」你拿回去好好研读。";
}
