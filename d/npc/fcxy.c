// arnzh.c �»�

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��Լ��", ({"fcxy"}));
	set("nickname",HIR"�䵱����"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����Ǹ������˸��䵱��ҵ�Ĵ���ʦ��Լ�죡\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
