#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"血玫瑰"NOR, ({"Gms"}));
        set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIM+"紫电护法 "+BLINK+HIG+"芊芊玉女"NOR);
        set("gender", "女性");
	set("age", 25);
	set("per",28);
	set("long",@LONG
她就是MUD里传说练功速度最慢的玩家，
她是MUD里最乐于助人的玩家之一……
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
