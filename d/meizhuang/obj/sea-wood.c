// sea-wood.c
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�Ϻ���ľ", ({ "sea wood", "wood", "sword" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����巢�����Ľ���ľ����\n");
                set("value", 2000);
                set("material", "wood");
                set("wield_msg", "$N�ӱ����Ϻ���ľ�γ������������С�\n");
                set("unwield_msg", "$N�����е�$n���²�ر���\n");
        }
        init_sword(150);
        setup();
}

