// Npc: /kungfu/class/shaolin/cheng-yu.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("����", ({
		"chengyu luohan",
		"chengyu",
		"xumi",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);


	set("nickname", "�����޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan-yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 85);
	set_skill("staff", 90);
	set_skill("pudu-zhang", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("staff", "pudu-zhang");
	map_skill("parry", "pudu-zhang");

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"

