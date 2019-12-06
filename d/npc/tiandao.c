#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"战无伤"NOR, ({"Tiandao"}));
        set("nickname",HIC"〖"HIY"傲世皇旗"HIC"〗"BLK"魔皇 "BLINK+HIR"九龙屠灵"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
这家伙很懒，什么都没留下。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
