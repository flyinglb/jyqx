
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����",({"icom"}));
      set("nickname",HIG "���齣��" NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"������������ͽ������\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
