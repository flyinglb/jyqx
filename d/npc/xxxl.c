#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"����"NOR, ({"Xxxl"}));
//        set("nickname",MAG" "NOR);
         set("gender", "Ů��");
	set("age", 25);
	set("per",29);
	set("long",@LONG
��һ������ʲô��û���¡�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
