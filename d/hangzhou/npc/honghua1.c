// honghua1.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�컨����", ({ "hong hua","hong","hua" }) );
	set("gender", "����");
	set("age", 25);
	set("long",
		"����λ����׳����������������ǰ���һ���컨��\n");
	set("combat_exp", 20000);
	set("shen_type", 1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("sword", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}
void init()
{
	if (random(2) == 1)
	message_vision(HIY "�컨�����˷ܵ����ĸ���$N���ܶ����ѹ��ʵۿ������������ˣ�\n" NOR, 
		this_player());
	else
	message_vision(HIY "�컨���ڳ���$N˵��ʮ�������ҵķֲ���أ����ʵ��ܲ��˵ģ�\n" NOR, 
		this_player());
}
