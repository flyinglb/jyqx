// ruanjian.c ��

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("��", ({ "ruanjian", "jian" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������������Ƴɵĸֽ���\n");
                set("value", 150);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(35);
        setup();
}

