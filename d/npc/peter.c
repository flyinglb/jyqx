
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��",({"peter"}));
	set("nickname", HIC"һ���߽���"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����ǵ���߳����Ƶġ��硹������\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
