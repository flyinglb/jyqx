
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����",({"rew"}));
	set("nickname", HIR"��ԭһ���"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����Ǵ�������\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
