#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "øºÃ‚" NOR, ({ "kaoti" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "±æ");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/zhu");
          }
    setup();
}
