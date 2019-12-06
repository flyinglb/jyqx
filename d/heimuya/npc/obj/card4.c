// card4.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"天香堂"+HIY+"令牌"NOR, ({"card4"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"这是日月神教下第四大堂天香堂令牌,上面刻有一柱天香。\n");
	set("unit", "块");
	set("weight", 10);
}
}
int query_autoload() { return 1; }

