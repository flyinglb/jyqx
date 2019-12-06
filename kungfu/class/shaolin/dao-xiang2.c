// Npc: /kungfu/class/shaolin/dao-xiang2.c
// Date: YZC 96/01/19

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();

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
	set_skill("damo-jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry",  "banruo-zhang");

	prepare_skill("strike", "banruo-zhang");

	create_family("������", 39, "����");

	set("inquiry", ([
		"��ҩ" :    (: ask_me_1 :),
		"С����" :    (: ask_me_2 :),
		"�󻹵�" :    (: ask_me_3 :)
	]));

	set("jin_count", 20);
	set("xiao_count",10);
	set("da_count",  5);

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

string ask_me_1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("jin chuangyao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (query("jin_count") < 1) return "�Բ��𣬽�ҩ�Ѿ�������";

	ob = new("/clone/misc/jinchuang");
	ob->move(this_player());

	add("jin_count", -1);

	message_vision("$N���һ����ҩ��\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}

string ask_me_2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("xiaohuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (query("xiao_count") < 1) return "�Բ���С�����Ѿ�������";

	ob = new("/clone/misc/xiaohuan-dan");
	ob->move(this_player());

	add("xiao_count", -1);

	message_vision("$N���һ��С������\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}

string ask_me_3()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("dahuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (query("da_count") < 1) return "�Բ��𣬴󻹵��Ѿ�������";

	ob = new("/clone/misc/dahuan-dan");
	ob->move(this_player());

	add("da_count", -1);

	message_vision("$N���һ�Ŵ󻹵���\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}



