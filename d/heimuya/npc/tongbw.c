//tonbaixiong.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int do_join(string arg);

void greeting(object);
void init();
void create()
{
	set_name("ͯ����", ({ "tongbai xiong","xiong"}) );
	set("gender", "����" );
	set("age", 75);
	set("title",HIW"�������"HIY"������"NOR"����");
	set("long", "���׷���ɢ, �������, ���ϵļ���ǣ��, \n"
                    "Բ��˫��, ���ϵ���Ѫ��Ȼ����, �������ǿɲ���\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
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

	set("chat_chance", 3);
	set("chat_msg", ({
		 "ͯ����ŭ��˫�۵�: ����û��, ��û���ѽ�! �����ֵ��㲻��ԩ����ѽ! ��\n",
	         "ͯ����̾��һ����˵�����ҺͶ����ֵܳ�������, �������ѵ�ʱ��, ���ǻ�û��������!��\n"
        }) );
	setup();
        carry_object(__DIR__"obj/zijinchui")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/card1")->wear();

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

