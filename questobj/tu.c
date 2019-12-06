#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIC "°ËØÔÊçÅ®Í¼" NOR, ({ "tu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "±¾");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/btshan/ouyangke");
          }
    setup();
}
