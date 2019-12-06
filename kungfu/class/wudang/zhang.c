// zhang.c ������

inherit NPC;
inherit F_MASTER;
string inquiry_book();

void create()
{
	set_name("������", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "��������");
	set("long", 
		"�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
		"��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
		"��ĸߴ��������꣬������⣬��ü�԰ס�\n");
	set("gender", "����");
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

	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "taoist");
	set("inquiry" , ([
	"�ưټ�" : (: inquiry_book :),
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

string inquiry_book()
{
	object me=this_player();
	object ob;

	if (present("changquan_book",me))
		return "������������ü˵�������Ѿ������ˣ���Ҫ̰�ģ�\n";
	else
	{
		ob=new("/clone/book/quanpu2");
		ob->move(me);
 		return "������Ц�����ܺã��Ȿ���������ˣ�\n";
	}
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
         if ((int)ob->query("guarded") < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "�������䵱���£��㻹��Ҫ���Ŭ�����ĲŶԡ�");
                return;
        }
	if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
		command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ����̫�����϶��µ㹦��");
		return;
	}
    if ((int)ob->query_skill("taoism", 1) < 80)
    {
        command("say ���䵱���˵����书��������书�벻����ѧ�ķ���");
        command("say " + RANK_D->query_respect(ob) +
            "�Ƿ�Ӧ�ö�������¾���");
        return;
    }
	if ((int)ob->query("shen") < 2000) {
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if (ob->query_int() < 30) {
		command("say ���䵱���书ȫ�ӵ��������");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("chat ����������������");
	command("chat �벻���ϵ��ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
	command("recruit " + ob->query("id"));
}
