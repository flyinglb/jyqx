// jianghuyiren.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("��������", ({ "jianghu yiren", "yiren" }));
	set("long", "����һ��������Ľ������ˣ�����ǣ��һֻ��˿����������糾֮ɫ��\n");
	set("gender", "����");
	set("age", 53);
	set("attitude", "friendly");
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);

	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 20);
	set("combat_exp", 30000);
	set("score", 10000);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

