// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
    set_name(HIW "玉斧" NOR, ({"yu axe","axe"}));
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一把用白玉做成的斧头。\n");
        set("value", 10000);
        set("flag",1);
        set("material", "bamboo");
        set("wield_msg", "$N从背上拔出一把"+HIW+"玉斧"+NOR+"，握在手中。\n");
        set("unwield_msg", "$N将一把"+HIW+"玉斧"+NOR+"插在背上。\n");
      }  
    init_axe(50,1);
    setup();
}   
