// gongsunzhi.c
// By Winzip 99.11.18

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
	{
	set_name("��ϰ", ({ "su xi","su" ,"xi"}));
	set("age", 24);
	set("combat_exp", 200000);
	set("title",HIG"�����ɵ��������"NOR);
	set("gender","����");
	set("attitude","taoism");
	set("str", 20);
	set("dex", 25);
	set("con", 28);
	set("int", 28);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("xuantian-force", 50);
	set_skill("sword", 60);
	set_skill("literate",50);
	set_skill("zhengliangyi-sword", 50);
	set_skill("yaoming-dodge", 50);
	set_skill("sanyin-unarmed",50);
	set_skill("unarmed",70);
           
	map_skill("dodge", "yaoming-dodge");
	map_skill("force", "xuantian-force");
	map_skill("parry", "zhengliangyi-sword");
	map_skill("sword", "zhengliangyi-sword");
	map_skill("unarmed","sanyin-unarmed");   
	prepare_skill("unarmed","sanyin-unarmed"); 


	set("max_jingli",400);
	set("jingli",500);
	set("max_jingli",500);
	set("jiali",10);
	set("max_neili",1000);
	set("neili",1000);
	set("eff_jing",800);
	set("jing",800);
	set("eff_qi",600);
	set("qi",600);
		create_family("������",7, "����");

	setup();
	carry_object("/clone/cloth/male3-cloth")->wear();
	carry_object(__DIR__"obj/sword")->wield();

}

void attempt_apprentice(object ob)
{
	message_vision("��ϰ����$N��ͷ��΢΢���˵�ͷ��\n",ob);
	command("recruit " + ob->query("id"));
	ob->set("title", HIG "�����ɵ���������" NOR);

	return;
}


