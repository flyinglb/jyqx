// weapon: xiuhua.c �廨��
// Jay 4/7/96

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIC"�廨��"NOR, ({ "xiuhua zhen", "zhen", "needle" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ϸĥ���廨�룬���廨�õľ��ѹ��ߡ�\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N��Ĵָ��ʳָ���޼����һ��$n��\n");
                set("unwield_msg", "$N�����е�$n����޼䡣\n");
        }
        init_sword(10);
        setup();
}

