// muliao.c 木料
// 2000-test-rain
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "木料" , ({"mu liao", "mu"}));
          set_weight(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "截");
                set("long", 
"一截刚从伐木场砍来的木料。\n");
                set("value", 1);
        }
        setup();
}

