// gangdao.c

#include <weapon.h>
inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(HIC"钢刀"NOR, ({ "blade" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄亮晃晃的"HIC"钢刀"NOR"，普通官兵的常备武器。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", HIY"$N「唰」的一声抽出一柄$n"HIY"握在手中。\n"NOR);
                set("unwield_msg", HIY"$N将手中的$n插回刀鞘。\n"NOR);
        }
        init_blade(20);
        setup();
}

