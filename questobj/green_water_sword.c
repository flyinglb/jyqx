// green-water-sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIG"碧水剑"NOR, ({ "green_water_sword", "jian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把通体晶莹剔透的剑!\n");
                set("value", 400);
                set("material", "crimsonsteel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
            set("dynamic_quest", "/d/huashan/npc/yue-lingshan");
        }
        init_sword(100);
        setup();
}
