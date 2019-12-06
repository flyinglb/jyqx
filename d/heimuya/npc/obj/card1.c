// card1.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIB"风雷堂"+HIY+"令牌"NOR, ({"card1"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"这是日月神教下第一大堂风雷堂令牌,上面刻有一风雷神。\n");
	set("unit", "块");
	set("weight", 10);
}
}
int query_autoload() { return 1; }

