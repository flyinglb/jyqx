
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"wwl"}));
	set("nickname", HIM "����һƬ��" NOR);
	set("title", "�һ����ڶ�������");
	set("gender", "Ů��");
	set("age", 20);
	set("long", 
		"�������һ����Ĳ�Ů���ƣ����������Ƹ�ƭȥ�ˡ�");
        setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
