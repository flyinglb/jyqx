
#include <weapon.h>
inherit AXE;

void create()
{
        set_name("AK-47", ({ "qiang", "AK-47" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻܺ��õĳ��ǹ.��\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N�Ӻ����ͳ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���������档\n");
        }
        init_axe(500000,0);
        setup();
}

