// tuoboseng.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
	set_name("�η�����", ({"seng ren","seng"}));
	set("long",
		"����һλ�����η����У�����������ϵ����Ĵ����˲�����\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 45);
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 25);
	set("dex", 23);
	set("max_qi", 380);
	set("max_jing", 300);
	set("neili", 380);
	set("max_neili", 380);
	set("jiali", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance", 30);

	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	setup();
	carry_object("/d/shaolin/obj/cloth")->wear();

	setup();
}

int accept_object(object me, object obj)
{
	if( obj->query("name") == "��վ�" )
	{
		command("smile");
		command("say �����ӷ𣬶�л��λ" + RANK_D->query_respect(me) + "�� ��");
		command("say ƶɮ�����Ȿ��վ�������ʯƺ�ϵ�ԭ�İ� ��");
	}

	return 1;
}

