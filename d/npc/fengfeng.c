#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"风风"NOR, ({"Fengfeng"}));
        set("nickname",HIB"玉萧神剑"NOR);
        set("gender", "男性");
	set("age", 25);
	set("per",28);
	set("long",@LONG
一介书生，三尺长剑，浪迹江湖，玉萧无情人有情
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
