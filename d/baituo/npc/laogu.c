//laogu.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

int ask_job();
int ask_help();
int ask_finish();
void create()
{
        set_name("老顾", ({ "lao gu","gu"}) );
	set("gender", "男性" );
	set("age", 45);
	set("long", "他在白驼山没其他事！只是掌管养蛇！\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 400);
	set("max_jing", 500);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 250000);
	set("score", 20000);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("parry", 80);
	set_skill("staff",80);
	
	set_skill("hamagong",70);
	set_skill("chanchu-bufa", 80);
	set_skill("lingshe-zhangfa", 80);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("inquiry", ([
                "蛇粮" : (:ask_job:),
                "help" : (:ask_help:),
                "解毒" : (:ask_help:),
                "food" : (:ask_job:),
                "finish" : (:ask_finish:),
        ]) );

	create_family("白驼山派",2,"弟子");

	setup();
        carry_object("/d/baituo/obj/baipao")->wear();
}

int ask_help()
{
        object who;
        who = this_player();
        if(!who->query_temp("job_btshan") || who->query("family/family_name") != "白驼山派") {
        write(name()+"哼了一声，并没有理会！\n");    
        return 1;
        }
        
         if((int)this_player()->query_condition("snake_poison") ==0) {
        write(name()+"斥道：没事不要找我！\n");    
        return 1;}
        else {
        write(name()+"说道：下次注意一点！\n");
        message_vision("说罢，便往你的伤口上敷了一点蛇药，你只觉得一阵清凉！\n", who);
        this_player()->apply_condition("snake_poison", 0);
        return 1;
        }
}

int ask_job()
{
        object who;
        who = this_player();
        if(!who->query_temp("job_btshan") || who->query("family/family_name") != "白驼山派") {
        write(name()+"冷冷的说道：蛇粮不能随便给你！\n");
        return 1;
        }
        
        if( objectp(present("she liang", who)) ) {
        write(name()+"对你说道：你不是有蛇粮了吗？快去喂蛇吧！\n");
        return 1;
        }
        message_vision(name()+"对$N说道：我正忙不过来呢！你帮我去喂蛇吧！\n", who);
        who->set_temp("job_btshan_tool",1);
        new(__DIR__"obj/sheliang")->move(who);
        tell_object(who, name()+"给你一包蛇粮。\n"); 
        return 1;
}
void attempt_apprentice(object ob)
{
        command("say 我不收徒弟！\n");
        return 0;
}

int ask_finish()
{
        object who;
        who=this_player();
        if(who->query("family/family_name") != "白驼山派") {
                write(name()+"说道：你问这个做什么？？\n");
                return 1;
        }
        if(!who->query_temp("finish_id")){ 
        message_vision(name()+"对$N怒道：还没有完成任务也想敷衍交差？\n", who);
        return 1;
        } else {
                message_vision(name()+"对$N说道：干的不错，辛苦你了！\n", who);
                who->delete_temp("finish_id");
                who->add("combat_exp",400+random(20));
                who->add("potential",30+random(10));
                return 1;
        }
}
