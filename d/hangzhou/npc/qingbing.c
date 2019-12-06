// qingbing.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��Ӫ���", ({ "qing bing","bing" }) );
	set("gender", "����");
	set("age", 25);
	set("long",
		"����λ��ִ��ǹ����Ӫ����������׺ݡ�\n");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("club", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();

        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/d/city/obj/junfu")->wear();
	add_money("silver", 10);
}
