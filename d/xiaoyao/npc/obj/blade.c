// gangdao.c

#include <weapon.h>
inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(HIC"�ֵ�"NOR, ({ "blade" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����λε�"HIC"�ֵ�"NOR"����ͨ�ٱ��ĳ���������\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", HIY"$N��ৡ���һ�����һ��$n"HIY"�������С�\n"NOR);
                set("unwield_msg", HIY"$N�����е�$n��ص��ʡ�\n"NOR);
        }
        init_blade(20);
        setup();
}

