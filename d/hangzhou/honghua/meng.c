// meng.c �Ͻ���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Ͻ���", ({ "meng jianxiong", "meng","jianxiong" }));
	set("nickname", HIC "����" NOR);
	set("long", 
"������������Ӣ�Ĵ���ӣ���ʦ�����Ĺ�����\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 31);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 18);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 60000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("throwing", 50);
	set_skill("mantian-xing", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("jingang-quan", 50);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "hunyuan-yiqi");
	map_skill("throwing", "mantian-xing");
	map_skill("unarmed", "jingang-quan");
	map_skill("parry", "jingang-quan");

	set("env/wimpy", 20);
	create_family("������", 52, "�׼ҵ���");
 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiedan")->wield();
}

