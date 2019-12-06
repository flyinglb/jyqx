#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"龙若情"NOR, ({"Xnet"}));
        set("nickname",HIC"〖"HIY"傲世皇旗"HIC"〗"HIW"玉后 "HIM+BLINK"风华绝代"NOR);
        set("gender", "女性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
她是冷琴阁龙家唯一的继承人，冷艳孤傲的绝世美女，一代魔皇--战无伤的娇妻。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
