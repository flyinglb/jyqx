#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"红货"NOR, ({"prize","hong huo"}));
        set("unit", "包");
        set("long", "一包从来往镖队那里抢来的红货。\n你可以交给马仇，从而得到他给的好处。\n");
        set("value", 0);
        setup();
}

