// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name(HIW "玉剑" NOR, ({"yu sword","sword"}));
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一把用蓝田玉做成的宝剑，但似乎很脆。\n");
        set("value", 10000);
        set("flag",2);
        set("material", "bamboo");
        set("wield_msg", "$N从剑鞘里抽出一把晶莹通透的"+HIW+"玉剑"+NOR+"。\n");
        set("unwield_msg", "$N将"+HIW+"玉剑"+NOR+"小心翼翼的插回剑鞘。\n");
    }
    init_sword(50,2);
    setup();
} 
