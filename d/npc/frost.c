#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"慕容火火"NOR, ({"Frost"}));
        set("nickname",HIY"【"HIW"慕容世家"HIY"】"HIG" 大当家　"HIR"火云邪神"NOR);
        set("gender", "男性");
	set("age", 25);
	set("per",28);
	set("long",@LONG
这家伙很懒，什么也没留下。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
