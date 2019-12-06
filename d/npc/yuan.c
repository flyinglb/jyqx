
#include <ansi.h>

inherit NPC;

void create()
{
         set_name(HIW"沉醉"NOR,({"Yuan"}));
	set("nickname", HIG"【"HIW"风"HIY"月"HIG"】"HIM"刀光"HIW"剑影 "BLINK+HIC"晓风"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是金庸群侠MUD里泥龄最长的最老实最乐于助人的玩家yuan。\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
