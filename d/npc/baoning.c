#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"天真"NOR, ({"Baoning"}));
	set("nickname",HIG"「玩新金庸群侠传II」 之 "HIR+HBWHT+BLINK"累累累"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",28);
	set("long",@LONG
他是第三代的玩家，很温柔！很体贴的人！很认真认真的人！本人很帅啊！
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
