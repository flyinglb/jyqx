#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( WHT "������" NOR, ({ "shengsibo" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/yang");
          }
    setup();
}
