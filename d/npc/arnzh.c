// arnzh.c �»�

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�»�",({"arnzh"}));
	set("nickname", HIY"���ս�"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�������䵱�������»𡹡�\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
