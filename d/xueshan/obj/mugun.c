#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("ľ��", ({ "mu gun","gun"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ľ�����ٿ���ü�����غ��ˣ��ɹ�����Ƭ���ˡ�\n");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_staff(5);
        setup();
}


