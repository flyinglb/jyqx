
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"黑紗公主"NOR,({"Heihei"}));
	set("nickname", HIW"異"BLINK+BLK"丗界"NOR+HBGRN+HIG"精靈"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"她是金庸群侠MUD里最大的呆子。\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
