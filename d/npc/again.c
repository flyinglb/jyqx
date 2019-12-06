#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"轮回"NOR, ({"Again"}));
        set("nickname",HIY"【"HIR"天魔宫"HIY"】"BLK"使者 "HIR"邪"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
正邪本没有分别，只是因为做错事的人多了，才会有了好人和坏人。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
