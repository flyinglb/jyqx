#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "水晶骰子" NOR, ({ "touzi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "副");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/zeng");
            set("long", "韦小宝送给曾柔的骰子。\n");
          }
    setup();
}
