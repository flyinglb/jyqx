
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����ȱ",({"basic"}));
	set("nickname", HIM "���ƽ���"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����Ǵ�������ȱ��\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
