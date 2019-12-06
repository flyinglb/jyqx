// /NPC ����Ů��

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����Ů��", ({ "nv lang", "nv"}));
	set("long",
	    "���Ǹ���Ľ��õ�Ů��, ��ɴ����,\n"
	    "һ˫��Ŀ��͸��һ˿ɱ����\n"
	   );
	set("gender", "Ů��");
	set("age", 20);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);

	set("combat_exp", 500000);
	set("score", 100000);
	set_skill("force", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",150);
	set_skill("strike", 150);
	set_skill("sword",150);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
 	set_skill("tianyu-qijian",150);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	create_family("���չ�",3,"����");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
}