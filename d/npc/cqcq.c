#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"傅采林"NOR, ({"Cqcq"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIB+"长老 "+HIY+"无法无天"NOR);
	set("gender", "男性");
	set("age", 35);
	set("per",29);
	set("long",@LONG
本名陈浪，是新金庸群侠传II第二代为数不多的玩家，后由疯火仔子
接手，便很快跻身一流高手，成为现在依旧活跃在泥潭的大侠。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
