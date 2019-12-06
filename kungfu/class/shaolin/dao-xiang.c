// Npc: /kungfu/class/shaolin/dao-xiang.c
// Date: YZC 96/01/19

inherit NPC;

string ask_me_1(string name);
string ask_me_2(string name);

void create()
{
	set_name("������ʦ", ({
		"daoxiang chanshi",
		"daoxiang",
		"chanshi",
	}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo-zhang", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("������", 39, "����");

        set("inquiry", ([
		"������" : (: ask_me_1, "huwan" :),
		"������" : (: ask_me_1, "huyao" :),
		"Ƥ����" : (: ask_me_1, "shoutao" :),
		"ƤΧ��" : (: ask_me_1, "weibo" :),
		"��ָ��" : (: ask_me_1, "zhitao" :),
		"ɮЬ"   : (: ask_me_1, "sengxie" :),
                "������" : (: ask_me_2, "beixin" :)
        ]));

	set("huju_count", 50);
	set("beixin_count", 5);

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";

	if (query("huju_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬷����Ѿ������ˡ�";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("huju_count", -1);

	message_vision("�����$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ�˷������ˡ�";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (query("beixin_count") < 1)
		return "��Ǹ�������ò���ʱ�������Ѿ������ˡ�";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("beixin_count", -1);

	message_vision("�����$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�����Ҫ��ס�����������Ƿ��������ƾ�˷������ˡ�";
}
