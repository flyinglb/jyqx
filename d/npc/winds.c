#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"风沙"NOR, ({"Winds"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIG+"天煞堂堂主 "+HIY+"风沙扑面"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",28);
	set("long",@LONG
他曾经是练得最快的玩家，也是很少说话的玩家……
同时，他也是一生一世只爱水柔晶的亲亲好老公！！！
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
