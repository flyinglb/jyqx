#include <ansi.h>

inherit NPC;

void create()

{
        set_name(HIW"风云"NOR, ({"Wind"}));
	set("nickname",HIC"云龙门开山祖师"NOR);
	set("gender", "男性");
	set("age", 20);
	set("per", 28);
	set("long", 
		"他就是当年的风，一剑平天下以后，功成身退，归隐山谷。\n"+
                "他就是天神风云，北京城、神龙岛皆出自他手。\n");
	

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
