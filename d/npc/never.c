#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"桃里里"NOR, ({"Never"}));
        set("nickname",HIR"【"HIW"七星楼"HIR"】 细雨护法 "HIW"冤家路窄"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他绝对不是高手。
能站在这里，只是对他在这里时间上的一种肯定。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
