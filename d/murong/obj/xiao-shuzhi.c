// /u/beyond/mr/obj/xiao-shuzhi.c С��֦
// this is made by beyond
// update 1997.6.20
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"С��֦"NOR,({ "xiao shuzhi", "shuzhi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֦");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ֦С��֦��\n");
                set("wield_msg", "$N�ó�һ֦$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(3);
        setup();
}

