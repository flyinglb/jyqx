// card2.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"白虎堂"+HIY+"令牌"NOR, ({"card2"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"这是日月神教下第二大堂白虎堂令牌,上面刻有一只白虎神。\n");
	set("unit", "块");
	set("weight", 10);
}
}
int query_autoload() { return 1; }

