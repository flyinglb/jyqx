#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( WHT "生意经" NOR, ({ "shengyijing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/tang");
            set("long", "这是一本唐楠家主传的生意经听说价值连城。\n");
          }
    setup();
}
