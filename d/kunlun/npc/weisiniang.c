// gongsunzhi.c
// By Winzip 99.11.18

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
	{
	set_name("������", ({ "wei siniang","wei" }));
	set("age", 31);
	set("combat_exp", 400000);
	set("title",HIG"�����ɵ��������"NOR);
	set("gender","Ů��");
	set("attitude","taoism");
	set("str", 22);
	set("dex", 25);
	set("con", 28);
	set("int", 22);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("xuantian-force", 100);
	set_skill("sword", 100);
	set_skill("zhengliangyi-sword", 100);
	set_skill("yaoming-dodge", 100);
	set_skill("sanyin-unarmed",80);
	set_skill("unarmed",80);
           
	map_skill("dodge", "yaoming-dodge");
	map_skill("force", "xuantian-force");
	map_skill("parry", "zhengliangyi-sword");
	map_skill("sword", "zhengliangyi-sword");
	map_skill("unarmed","sanyin-unarmed");   
	prepare_skill("unarmed","sanyin-unarmed"); 

	set("max_jingli",800);
	set("jingli",800);
	set("jiali",20);
	set("max_neili",2000);
	set("neili",2000);
	set("eff_jing",800);
	set("jing",800);
	set("eff_qi",1200);
	set("qi",1200);
		create_family("������",5, "����");

setup();
	carry_object("/clone/cloth/female3-cloth")->wear();
	carry_object(__DIR__"obj/sword")->wield();

}

void attempt_apprentice(object ob)
{
	message_vision("����������$N��ͷ��΢΢���˵�ͷ��\n",ob);
	command("recruit " + ob->query("id"));
	ob->set("title", HIG "�����ɵ���������" NOR);

	return;
}
