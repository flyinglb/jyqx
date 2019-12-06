// Npc: /kungfu/class/shaolin/dao-cheng.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("������ʦ", ({
		"daocheng chanshi",
		"daocheng",
		"chanshi",
	}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 21);
	set("int", 20);
	set("con", 19);
	set("dex", 24);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo-zhang", 50);
	set_skill("claw", 52);
	set_skill("longzhua-gong", 52);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "longzhua-gong");

	prepare_skill("claw", "longzhua-gong");

	create_family("������", 39, "����");

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}


#include "/kungfu/class/shaolin/dao.h"

