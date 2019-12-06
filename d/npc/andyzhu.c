#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"龙剑"NOR, ({"Andyzhu"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIC+"楼主 "+BLK+"魔龙"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他是新金庸群侠传II中第二代高手中的和平主义者，为人恬谈
宁静，颇有长者风范。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
