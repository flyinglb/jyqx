// baizhen.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "bai zhen", "bai", "zhen"}) );
	set("title", "��ǰ����");
	set("nickname", HIY"��צ"HIB"����"NOR);
	set("gender", "����");
	set("age", 64);
	set("long",
		"�����������ɸ��֣���ʮ��ǰ�ͳ��������ˡ�\n");
	set("combat_exp", 450000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed", 95);
	set_skill("blade", 95);
	set_skill("claw", 95);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	set_skill("sougu", 90);
	set_skill("lingxu-bu", 90);
	map_skill("dodge", "lingxu-bu");
	map_skill("claw", "sougu");
	map_skill("parry", "sougu");
	prepare_skill("claw", "sougu");

	setup();
        carry_object("/d/city/obj/tiejia")->wear();

	add_money("silver", 30);
}
