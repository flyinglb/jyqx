#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"孤独"NOR, ({"Songxin"}));
        set("nickname",HIR"【"HIW"七星楼"HIR"】 "HIM"迅雷护法 "HIY"孤风残月"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他是一个另人难以琢磨的玩家，练功的速度也很快，
平时心情好就帮助新人，但是反过来就……
而且他特别的记仇，这种人还是少得罪为妙。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
