#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"孤月"NOR, ({"Fangz"}));
        set("nickname",HIR"【"HIW"七星楼"HIR"】"HIG"天权堂主 "HIY"无相心魔"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
生命诚可贵，爱情价更高，若为自由顾，两者皆可抛。
他是本mud中最不爱说话的玩家之一，所以知道他的人并不多。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
