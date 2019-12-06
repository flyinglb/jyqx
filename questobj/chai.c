#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIW "碧血钗" NOR, ({ "chai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "颗");
            set("material", "玉");
            set("dynamic_quest", "/d/city/yingying");
            set("long", "逍遥派的帮主的信物。\n");
          }
    setup();
}
