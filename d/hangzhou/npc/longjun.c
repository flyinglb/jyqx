// longjun.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "long jun", "long", "jun"}) );
	set("title", "��ǰ����");
	set("gender", "����");
	set("age", 32);
	set("long",
		"�����Ǵ��ڸ��֣�һ��ι��������������ƥ��\n");
	set("combat_exp", 300000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed", 65);
	set_skill("throwing", 65);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("mantian-xing", 60);
	set_skill("shaolin-shenfa", 60);
	map_skill("throwing", "mantian-xing");
	map_skill("parry", "mantian-xing");
	map_skill("dodge", "shaolin-shenfa");

	setup();
        carry_object("/d/city/obj/tiejia")->wear();
        carry_object("clone/weapon/jili")->wield();

	add_money("silver", 10);
}
