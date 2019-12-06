// murong-bo.c  慕容博

inherit NPC;
inherit F_MASTER;
 

void create()
{
	set_name("慕容博",({"murong bo","murong","bo"}));
        set("title","姑苏慕容老爷子");
        set("nick","以彼之道 还施彼身");
	set("long", 
              "他就是天下号称以彼之道，还彼之身的姑苏慕容博。\n"
              "他脸上带着不可一世的笑容。\n");
        set("age", 57);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
        set("combat_exp", 2000000);
	set("score", 50000);                
/*
        set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
        }));
*/
        set_skill("xingyi-zhang",200);
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("canhe-zhi", 200);
	set_skill("murong-jianfa",200);       
        set_skill("shenyuan-gong", 200);
	set_skill("yanling-shenfa", 200);
        set_skill("douzhuan-xingyi", 200);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("murong-daofa", 200);
        set_skill("blade",200);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
        
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
        carry_object(__DIR__"obj/blade")->wield();   
        create_family("姑苏慕容",1,"弟子");

       	set("inquiry", 
                ([
                        "name" : "我就是以彼之道，还施彼身的姑苏慕容博。\n",
                        "here" : "这里是少林寺的藏经楼。\n",
                        "rumors" : "我那慕容复儿在武林之中闯出了名头，老爷子我是真高兴呀！\n",
                        
                ]));
       	setup();
	
}
void attempt_apprentice(object ob)
{
        object obj;
        string new_name; 
        obj = present("jiaxin", ob);
        
        if( !objectp(obj) || !(int)obj->query("is_murong_fu") ) {
                command("say 我慕容博岂能随便收徒!");
                return;
        }
        
        obj->move(VOID_OB);
        destruct(obj);
        
        if( !ob->query_temp("marks/bai_bo") ) {
                command("say 这封信你是从哪弄来的？看来你也是不会说的了");
                command("say 受死吧！");
                this_object()->kill_ob(ob);
                ob->fight_ob(this_object());
                return ;
        }
        
        command("say 好吧，既然" + RANK_D->query_respect(ob) + "有我儿的信件，难为你" +
		"如此辛苦跑来，我就收下你吧。");
 
        new_name = "慕容" + (string)ob->query("name")[2..3];
        ob->set("name", new_name);
        command("say 从今以后你就叫做" + new_name + "，希望你能把慕容功夫发扬光大！");
        command("recruit " + ob->query("id"));
        //command("chat 淡淡一笑，谁言 以彼之道 还施彼身 绝迹江湖！");
        //command("chat* haha"); 
}
 


