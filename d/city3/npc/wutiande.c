// wutiande.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("�����", ({ "wu tiande", "wu" }));
	set("title", "�ɶ��ᶽ");
	set("shen_type", 0);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"����´���ԭ��ֻ��һ���ν����ԴӸ��������С�����󣬾�Ȼ���˺�ͨ��������\nΪ�ܱ������ܳ���ȫ��֮����\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

