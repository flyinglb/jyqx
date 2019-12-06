#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"跋寒锋"NOR, ({"Boboy"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIC+"光明左使 "+HIB+"天外流星"NOR);
	set("gender", "男性");
	set("age", 26);
	set("per",28);
	set("long",@LONG
他无疑是新金庸群侠传II的后起之秀，践踏着坎坷的大侠
之路，终于成为一代名人。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
