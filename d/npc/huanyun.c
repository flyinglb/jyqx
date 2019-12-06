#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"羽夜寒"NOR, ({"Huanyun"}));
        set("nickname",HIC"〖"HIY"傲世皇旗"HIC"〗"HIW"圣帝 "HIC+BLINK"天地任逍遥"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他在这里可是不容易了，象当年老邓那样三起三落……
但终究练成了盖世武功，傲然于天地之间……
将来的江湖中，不知是否还能见到这样百折不挠的人……
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
