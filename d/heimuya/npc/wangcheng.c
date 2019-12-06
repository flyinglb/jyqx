// wangcheng.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int do_join(string arg);

void create()
{
	set_name("����", ({ "wang cheng","wang"}) );
	set("gender", "����" );
	set("title",HIW"�������"HIY"������"NOR"����");
	set("age", 65);
	set("long", "������İ��֣�������Ц����ʵΪ��ʮ�ֺݶ���\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 150);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("sword",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family(HIW"�������"NOR,2,"���� ����������");

	setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
     command("say ���ǻ���֮��, ��ô����ͽ�ء�׳ʿ������ذ�!\n");
}
void init()
{
	add_action("do_join","join");
}

#include "/d/heimuya/npc/riyueshenjiao.h"; 

