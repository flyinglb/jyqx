// xem_sword.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIR"�ط罣"NOR, ({ "huifeng", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N��������, һ��$n�ƿն���, ����$N�����С�\n");
                set("unwield_msg", "$n��$N����һԾ����, Х�����ƿն�ȥ��\n");
        }
        init_sword(30);
        setup();
}

