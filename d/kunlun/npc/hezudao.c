inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
	{
	set_name("�����", ({ "he zudao","he"}));
	set("age", 100);
	set("combat_exp", 3500000);
	set("title",HIG"�����ɿ�ɽ��ʦ"NOR);
	set("gender","����");
//	set("attitude","taoism");//?
	set("str", 30);
	set("dex", 30);
	set("con", 30);
	set("int", 30);

	set("max_jingli",3000);
	set("jingli",3000);
	set("jiali",200);
	set("max_neili",5000);
	set("neili",5000);
	set("eff_jing",1400);
	set("jing",1400);
	set("eff_qi",3500);
	set("qi",3500);

	set_skill("force", 220);
	set_skill("sword", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("unarmed",200);
	set_skill("literate",180);
	set_skill("chess",150);
	set_skill("music",150);
	set_skill("xuantian-force", 220);
	set_skill("zhengliangyi-sword", 250);
	set_skill("chiqing-jian", 250);
	set_skill("yaoming-dodge", 250);
	set_skill("sanyin-unarmed",200);

	map_skill("dodge", "yaoming-dodge");
	map_skill("force", "xuantian-force");
	map_skill("parry", "chiqing-jian");
	map_skill("sword", "chiqing-jian");
	map_skill("unarmed","sanyin-unarmed");   
	prepare_skill("unarmed","sanyin-unarmed"); 

	create_family("������",1, "�����ɿ�ɽ��ʦ");

setup();
	carry_object("/clone/cloth/male6-cloth")->wear();
	carry_object(__DIR__"obj/shansword")->wield();

}

void attempt_apprentice(object ob)
{
	if (ob->query_skill("xuantian-force",1) <= 150)
	{
	command("say ����ڹ���Ϊ�������һ����ܽ���ʲô��");
	return;
	}
	message_vision("�����������Ц�����벻����������Ϊ�������㹱�ס���\n",ob);
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
	ob->set("class", "swordsman");
	ob->set("title", HIG "�����ɵڶ�������" NOR);

	return;
}


