
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"老笔"NOR,({"Cbr"}));
	set("nickname", HIG"【"HIW"风"HIY"月"HIG"】"HIM"刀光"HIW"剑影 "BLINK+HIR"残月"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是金庸群侠MUD里泥龄最长的最老实最乐于助人的玩家cbr。\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
