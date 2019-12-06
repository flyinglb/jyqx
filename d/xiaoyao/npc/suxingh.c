// suxingh.c
// shilling 97.2

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_book();
int ask_job();

void create()
{
	set_name("���Ǻ�",({"su xinghe","su"}));
	set("gender", "����" );
	set("nickname", "�ϱ�����");
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
"���˾��Ǻųƴϱ����˵����Ǻӣ���˵�������Ʊ磬 \n"
"��һ�������е����ߣ��������书Ҳ��������֪��\n");

	set("combat_exp", 500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
		"���ܵص�" :(:ask_me:),
		"�ؼ�"     :(:ask_book:),
                "job"      :(:ask_job:),
                "����"     :(:ask_job:),
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

	create_family("��ң��", 2, "����");
	set("title","��ң�ɵڶ��������");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}

int ask_job()
{
        object who = this_player();
        //int pot = (int)(who->query("potential")) - (int)(who->query("learned_points"));

        if(who->query("family/family_name") != "��ң��") {
        write(name()+"����˵����������ң�ɻ�������Ҫ������æ��лл�����š�\n");
        return 1;
        }
        if(who->query_temp("job_xiaoyao")) {
        write(name()+"����˵�����㲻�ǻ�������ô����ȥ������Ļ\n");
        return 1;
        }
        //if(pot >= who->query_int() * 30 ) {
        //write(name()+"���´�������һ��˵����������ûʲô���������ɵġ���\n"
        //"�㻹�����ֽ��϶��µ㹤��ɣ�\n");
        //return 1;
        //}
        if(who->query("combat_exp") > 500000 ) {
        write(name()+"����˵������ЩС�»�����С����ȥ���ɡ�\n");
        return 1;
        }
        who->set_temp("job_xiaoyao",1);//��������
        message_vision(name()+"��$N˵�����ðɣ����ȥ����ͽ��Ҫ����ȥ��\n", who);
        return 1;
}

void attempt_apprentice(object ob)
{

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ����ѧ���϶��µ㹦��");
		return;
	}

	command("say �ðɣ��Ҿ��������ˣ����Ҫ���Ŭ������");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
	object ob;
	mapping fam; 

	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"��Ҫ�ؼ��͵ü�����ң�ɡ�";
	}
	command("sigh");
	return"���ɵ��书�ؼ�����һ�������ܵĵط�����Ҳûȥ����";
}
string ask_me()
{
	object ob;
	mapping fam; 

	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"��Ҫ֪���ܵ��͵ü�����ң�ɡ�";
	}
	command("sigh");
	return"���ɵ��ܵ��ڻ�ɽ֮�ϣ����Ǽ��ա�������Ȥ����ȥ������";
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "scholar");
}
