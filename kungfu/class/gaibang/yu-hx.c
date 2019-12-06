// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({"yu hongxing", "yu", "hongxing"}));
	set("title", "ؤ��˴�����");
	set("gender", "����");
	set("age", 30);
	set("long", 
		"����λЦ���е�ؤ��˴����ӣ����Զ��ǣ����С���á�\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 420);
	set("max_jing", 330);
	set("neili", 780);
	set("max_neili", 780);
	set("jiali", 42);
	
	set("combat_exp", 82000);
	
	set_skill("force", 78); 
	set_skill("huntian-qigong", 76); 
	set_skill("unarmed", 78); 
	set_skill("xianglong-zhang", 80); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 82); 
	set_skill("parry", 81); 
	set_skill("begging", 80); 
	set_skill("stealing", 90); 
	set_skill("checking", 70); 
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 19, "����");
	setup();
       carry_object(__DIR__"obj/beggar-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("int") < 25 ) return;
	command("say �����������Ϊ����ֻ���߹������˼Һ��Ҳ��ر���Щ����ͽ����");
	command("say ��Ҷ�ҪΪ��Զ���밡��");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
