
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIW " È–≈" NOR, ({ "shuxin" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "∑‚");
            set("value", 0);
            set("material", "cloth");
          }
    setup();
}
