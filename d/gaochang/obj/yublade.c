// blade.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW "玉刀" NOR, ({ "yu blade","blade" }) );
    set_weight(4000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "柄");
        set("value", 20000);
        set("flag",2);
        set("material", "iron");
                set("long", "这是一把用白玉雕刻而成的玉刀，刀身微微透出一股寒气。\n");
                set("wield_msg", "$N抽出一把$n握在手上\n");
        set("unequip_msg", "$N将手中的$n插入腰间的刀鞘　\n");
    }
    init_blade(25,2);
    setup();
}
