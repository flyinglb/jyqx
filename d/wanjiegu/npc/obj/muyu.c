// muyu.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ľ�㴸", ({ "muyu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻܳ�����ľ�㴸\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(15);
        setup();
}

