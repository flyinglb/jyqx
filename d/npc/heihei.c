
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"�ڼ�����"NOR,({"Heihei"}));
	set("nickname", HIW"��"BLINK+BLK"�F��"NOR+HBGRN+HIG"���`"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"���ǽ�ӹȺ��MUD�����Ĵ��ӡ�\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
