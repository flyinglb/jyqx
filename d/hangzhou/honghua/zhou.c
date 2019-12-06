// zhou.c ����Ӣ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����Ӣ", ({ "zhou zhongying", "zhou","zhongying" }));
	set("title", HIC "����ׯׯ��" NOR);
	set("nickname", HIW "����" NOR);
	set("long", 
"���׷�Ʈ�����������壬�����������ֵ�����������������Ӣ��\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 61);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 140);
	set_skill("dodge", 140);
	set_skill("unarmed", 140);
	set_skill("parry", 140);
	set_skill("throwing", 140);
	set_skill("mantian-xing", 140);
	set_skill("hunyuan-yiqi", 140);
	set_skill("jingang-quan", 140);
	set_skill("shaolin-shenfa", 140);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "hunyuan-yiqi");
	map_skill("throwing", "mantian-xing");
	map_skill("parry", "jingang-quan");
	map_skill("unarmed", "jingang-quan");

	set("env/wimpy", 20);
	create_family("������", 51, "�׼ҵ���");
 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiedan")->wield();
}

