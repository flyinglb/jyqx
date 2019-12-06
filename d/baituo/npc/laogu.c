//laogu.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

int ask_job();
int ask_help();
int ask_finish();
void create()
{
        set_name("�Ϲ�", ({ "lao gu","gu"}) );
	set("gender", "����" );
	set("age", 45);
	set("long", "���ڰ���ɽû�����£�ֻ���ƹ����ߣ�\n");
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
                "����" : (:ask_job:),
                "help" : (:ask_help:),
                "�ⶾ" : (:ask_help:),
                "food" : (:ask_job:),
                "finish" : (:ask_finish:),
        ]) );

	create_family("����ɽ��",2,"����");

	setup();
        carry_object("/d/baituo/obj/baipao")->wear();
}

int ask_help()
{
        object who;
        who = this_player();
        if(!who->query_temp("job_btshan") || who->query("family/family_name") != "����ɽ��") {
        write(name()+"����һ������û����ᣡ\n");    
        return 1;
        }
        
         if((int)this_player()->query_condition("snake_poison") ==0) {
        write(name()+"�����û�²�Ҫ���ң�\n");    
        return 1;}
        else {
        write(name()+"˵�����´�ע��һ�㣡\n");
        message_vision("˵�գ���������˿��Ϸ���һ����ҩ����ֻ����һ��������\n", who);
        this_player()->apply_condition("snake_poison", 0);
        return 1;
        }
}

int ask_job()
{
        object who;
        who = this_player();
        if(!who->query_temp("job_btshan") || who->query("family/family_name") != "����ɽ��") {
        write(name()+"�����˵�����������������㣡\n");
        return 1;
        }
        
        if( objectp(present("she liang", who)) ) {
        write(name()+"����˵�����㲻�����������𣿿�ȥι�߰ɣ�\n");
        return 1;
        }
        message_vision(name()+"��$N˵��������æ�������أ������ȥι�߰ɣ�\n", who);
        who->set_temp("job_btshan_tool",1);
        new(__DIR__"obj/sheliang")->move(who);
        tell_object(who, name()+"����һ��������\n"); 
        return 1;
}
void attempt_apprentice(object ob)
{
        command("say �Ҳ���ͽ�ܣ�\n");
        return 0;
}

int ask_finish()
{
        object who;
        who=this_player();
        if(who->query("family/family_name") != "����ɽ��") {
                write(name()+"˵�������������ʲô����\n");
                return 1;
        }
        if(!who->query_temp("finish_id")){ 
        message_vision(name()+"��$Nŭ������û���������Ҳ����ܽ��\n", who);
        return 1;
        } else {
                message_vision(name()+"��$N˵�����ɵĲ����������ˣ�\n", who);
                who->delete_temp("finish_id");
                who->add("combat_exp",400+random(20));
                who->add("potential",30+random(10));
                return 1;
        }
}
