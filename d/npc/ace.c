#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"无双"NOR, ({"Ace"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIB+"长老 "+HIW+"天下无双"NOR);
	set("gender", "女性");
	set("age", 25);
	set("per",28);
	set("long",@LONG
她就是疯火仔子的娇妻，是第二代比较早期的玩家了，只是中间间断
了很久，才步许多第三代高手的后尘成为一世名人。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
