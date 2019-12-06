// card3.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"青龙堂"+HIY+"令牌"NOR, ({"card3"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"这是日月神教下第三大堂青龙堂令牌,上面刻有一条青龙神。\n");
	set("unit", "块");
	set("weight", 10);
}
}
int query_autoload() { return 1; }

