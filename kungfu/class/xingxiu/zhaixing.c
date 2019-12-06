// zhaixing.c ժ����

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_book();

void create()
{
	set_name("ժ����", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "�����ɴ�ʦ��");
	set("long", 
		"�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�\n"
		"����ʮ���꣬�����������۹���͸��һ˿����֮����\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 40000);

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("throwing", 70);
	set_skill("feixing-shu", 80);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 80);
	set_skill("chousui-zhang", 80);
	set_skill("claw", 80);
	set_skill("sanyin-wugongzhao", 80);
	set_skill("parry", 70);
	set_skill("poison", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"���ĵ�"    : (: ask_me :),
		"�ؼ�"      : (: ask_book :),
		"��ɽ����"  : (: ask_book :),
	]));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("������", 2, "����");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("dan_count") < 1)
		return "�������ˣ�û�����ĵ��ˡ�";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "��Щ���ĵ������õ��˰ɡ�";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ�����ûʲôʣ���ˡ�";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����û�ȥ�úÿ����ɡ�";
}
