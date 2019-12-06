#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "龙女花" NOR, ({ "hua" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "株");
            set("material", "玉");
            set("dynamic_quest", "/d/gumu/npc/longnv");
            set("long", "小龙女的龙女花。\n");
          }
    setup();
}
