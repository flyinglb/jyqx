
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("����", ({"huang rong", "huang", "rong"}));
    set("title", "�һ�����������Ů");
    set("gender", "Ů��");
    set("age", 18);
	set("long", 
        "�����һ������Ķ���Ů�������ڵ����������������������Ů�������۰���\n"
        "���������ѷ��ϲ���Ĵ����ܡ�\n");

	set("attitude", "peaceful");
	
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 500);
    set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 0);
	
    set("combat_exp", 150000);
    set("score", 0);
	
    set_skill("force", 60);
    set_skill("bibo-shengong", 80);
    set_skill("unarmed", 80);
    set_skill("luoying-zhang", 80);
       set_skill("dodge", 100);
    set_skill("anying-fuxiang", 80);
    set_skill("parry", 85);
    set_skill("sword", 80);
    set_skill("luoying-shenjian",80);
	
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
	
    create_family("�һ���", 2, "����");
	setup();
    carry_object(__DIR__"obj/ruanwei")->wear();
    carry_object(__DIR__"obj/shudai")->wear();

}

void init()
{
    object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
        if ((!myfam || myfam["family_name"] != "�һ���") &&
			(!wizardp(ob))) {
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
        }
}

void saying(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if ((string)ob->query("gender") == "����")
        message_vision("\n�������־���֮ɫ��������$Nһ�ۣ�˵����������ʲô�ˣ�"
        "�����Ҵ��ҵĹ뷿��\n�ٲ�����ȥ��������ô���㣡��\n", ob);
    else
        message_vision("\n���ؿ��˿�$N��˵�������þ�ÿ���������ˣ�"
        "��֪��λ�������Ҿ�������Ϣ��\n", ob);
}

void attempt_apprentice(object ob)
{
    command("say �������ôС����ͽ�ܣ�������Ц��������");
}
