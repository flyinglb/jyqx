// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
    set_name(YEL "黄金斧" NOR, ({"axe","gold axe"}));
    set_weight(210000);

    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一把"+YEL+"黄金"+NOR+"打造的斧头。\n");
        set("value", 500000);
        set("material", "gold");
        set("get_拉1",1);
        set("weapon_prop/dodge", 50);
        set("wield_msg", "$N从背上拔出一把"+YEL+"黄金斧"+NOR+"，握在手中。\n");
        set("unwield_msg", "$N将一把"+YEL+"黄金斧"+NOR+"插在背上。\n");
      }  
    init_axe(500,1);
    setup();
}   
