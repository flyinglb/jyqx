//jiabu.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("�ֲ�", ({ "jia bu", "jia", "bu"}) );
	set("gender", "����" );
	set("age", 45);
	set("title",HIW"�������"HIC"������"NOR"����");
	set("long", "����������������̫��Ѩ�߸߹��𣬱������һöö�����Ƶġ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 15);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("jiali", 200);
	set_skill("force", 140);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-dao", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji-dao");
	create_family(HIW"�������"NOR,2,"���� �����ó���");

	set("chat_chance", 2);
	set("chat_msg", ({
		 "�ֲ�̾��: ��������Ȱ��ڣ��������Ʊ������Ǳ�����֪�����������ӡ���\n"
        }) );
	setup();
        carry_object(__DIR__"obj/dadao")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
      

}



void attempt_apprentice(object ob)
{
     command("say �����Ƥë�����ң�����!\n");
}

