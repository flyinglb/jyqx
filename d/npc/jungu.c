// jungu.c ˮ���

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ˮ���", ({"jungu"}));
	set("nickname", GRN"�һ�����ɽ��ʦ"NOR);
	set("gender", "Ů��");
	set("age", 20);
	set("long", 
		"�������һ����Ĵ�ʼ�ˡ�ˮ�������\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
