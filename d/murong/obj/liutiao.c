// /u/beyond/mr/obj/liutiao.c ����
// this is made by beyond
// update 1997.6.20
#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(GRN"����"NOR,({ "liu tiao", "liutiao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֦");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ֦��������\n");
                set("wield_msg", "$N���һ֦$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_whip(3);
        setup();
}

