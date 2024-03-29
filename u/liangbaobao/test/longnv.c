// longnv.c 小龙女

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

string ask_yunv();
string ask_yangguo();
string ask_yang();
string ask_me();

void create()
{
        set_name("小龙女", ({"long nv", "long"}));
        set("gender", "女性");
        set("age", 18);
        set("long",
                "她一生爱穿白衣，当真如风拂玉树，雪裹琼苞，兼之生性清冷，\n"
                "实当得起“冷浸溶溶月”的形容。\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance_combat", 9);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小龙女幽幽地道：“不知过儿现在在哪里？可有看到我刺在玉蜂翅上的字？”\n", 
                "小龙女喃喃道：“玉女剑与全真剑合壁，是可天下无敌。可是...哪里去找这一个人呢？”\n",
                "小龙女深深地叹了口气，转过头去。\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);

        set("combat_exp", 800000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("yunv-xinfa", 150);    //玉女心法
        set_skill("sword", 150);
        set_skill("yunv-jian", 150);     //玉女剑
        set_skill("quanzhen-jian",140);  //全真剑
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 160);   //玉女身法
        set_skill("parry", 150);
        set_skill("hubo", 120);          //双手互搏
        set_skill("unarmed",150);
        set_skill("meinv-quan", 160);    //美女拳法
        set_skill("literate",120);
        set_skill("qufeng",200);         //驱蜂之术

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("古墓派", 3, "弟子");

        set("book_count", 1);
        set("count",1);

        set("inquiry", ([
                "下落" : (: ask_yangguo :),
                "过儿" : (: ask_me :),
                "杨过" : (: ask_yang :),
                "玉女剑法" : "玉女剑法和全真剑法合壁，天下无敌！\n",
                "古墓派" : "我的林祖师爷爷本来和重阳先师是一对璧人，可是...\n",
                "玉女心经" : (: ask_yunv :),
        ]) );

        set("env/wimpy", 40);
        setup();

//        carry_object(__DIR__"obj/shunvjian")->wield();
//        carry_object(__DIR__"obj/baipao")->wear();

}

void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
        	command("say 尊容实在不敢恭维，恐怕学不了玉女心法。\n");
	}
	else
	{
	        command("say 好吧，我就收下你这个徒弟了。\n");
        	command("recruit " + ob->query("id"));
	}
}

string ask_yunv()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
                return RANK_D->query_respect(this_player()) +
                "与本派毫无瓜葛，何以问起本派的心经？";
        if (query("book_count") < 1)
                return "你来晚了，本派的玉女心经已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing1");
        ob->move(this_player());
        return "好吧，这本「玉女心经」你拿回去好好研读。";
}

string ask_yang()
{
        object me=this_player();
        me->set_temp("tmark/杨",1);
        return("你知道过儿的下落吗?\n");
}

string ask_yangguo()
{
        object me=this_player();

        if( me->query_temp("tmark/杨") > 1 ) 
                return("过儿就在古墓后山里，你去找找吧。\n");
        me->add_temp("tmark/杨",1);
        return("我也在找过儿，如果你有他的下落，请告诉我。\n");
}

string ask_me()
{
        object ob;

        if(query("count") < 1)
                return "你知道过儿的下落？";

        add("count", -1);
        ob=new(__DIR__"obj/junzijian");
        ob->move(this_player());
        return "这柄君子剑送给你做个信物，见到过儿的时候请交给他。";
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "古墓派") return 1 ;
        if ((int)ob->query_temp("tmark/龙") == 1 )
        message_vision("小龙女叹了口气，看看$N，说道：咱们的缘分已经尽了,\n"
                          "我也没什么东西可教你的了。\n", ob);
        if (!(int)ob->query_temp("tmark/龙"))
                return 0;
        ob->add_temp("tmark/龙", -1);
        return 1;
}

int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="yufeng" ) {
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);
                if (!(int)who->query_temp("tmark/龙")) who->set_temp("tmark/龙",0);
                message_vision("小龙女捧着玉蜂，幽幽地叹了口气，说道：\n"
                               "难得你还有心找到了我的玉蜂送回来，你可\n"
                               "以从我这里学点功夫。\n", who);
                who->add_temp("tmark/龙", 80);
                //ob->die();
                return 1;
        }
        return 0;
}

void destroying(object me, object obj)
{
      me->add_encumbrance(-obj->query_weight());
        destruct(obj);
        return;
}
