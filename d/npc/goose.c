
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����",({"goose"}));
	set("nickname", HIB "�Ͻл�"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"������ؤ��������֡�\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
