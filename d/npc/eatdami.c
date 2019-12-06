#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"吃大米"NOR, ({"Eatdami"}));
	set("nickname",HIR"系统天神"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long", 
		"他就是新金庸群侠传II的系统制作人。\n");
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
