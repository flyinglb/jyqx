// guxu.c ����

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�������", ({ "guxu daozhang", "guxu" }));
	set("long", 
		"�����������۵ĵ��ӹ��������\n"
		"��������ʮ�꣬�����䵱�ɵ����¡�\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
        set("class", "taoist");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("combat_exp", 60000);
	set("score", 8000);

	set_skill("force", 60);
	set_skill("taiji-shengong", 40);
	set_skill("dodge", 60);
	set_skill("tiyunzong", 40);
	set_skill("unarmed", 60);
	set_skill("taiji-quan", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);
	set_skill("taoism", 60);
//  	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("�䵱��", 3, "����");
	set("class", "taoist");

	set("inquiry", 
		([
			"���¾�" : (: ask_me :),
		]));
                                
	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if ((int)ob->query("guarded") < 5) {
                command("say " + RANK_D->query_respect(ob) +
                        "�������䵱���£��㻹��Ҫ���Ŭ�����ĲŶԡ�");
                return;
        }
	if ((int)ob->query("shen") < 0) {
		command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵĵ����澭���ڴ˴���";
        add("book_count", -1);
        ob = new("/clone/book/daodejing-ii");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}
