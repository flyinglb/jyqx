#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"静瘦"NOR, ({"Xxxl"}));
//        set("nickname",MAG" "NOR);
         set("gender", "女性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
这家伙很懒，什么都没留下。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
