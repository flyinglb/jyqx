// /NPC zhujian.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��", ({ "zhu jian", "zhu"}));
	set("long",
	    "���Ǹ���ò毺õ�Ů��, ��������,\n"+
	    "�������, �������.\n"+
	    "���ܾ������ļ�����.\n");
	set("gender", "Ů��");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 50000);
	set("score", 10000);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("hand",70);
	set_skill("strike", 70);
	set_skill("sword",80);

	set_skill("zhemei-shou",80);
	set_skill("liuyang-zhang",80);
	set_skill("tianyu-qijian",80);
	set_skill("yueying-wubu",80);
	set_skill("bahuang-gong", 70);

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
	carry_object("/d/lingjiu/obj/key");
        add_money("silver",15);
}

