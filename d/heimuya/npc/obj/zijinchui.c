// bishuijian.c
// for ����ɺ

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("�Ͻ�", ({ "zijin chui", "chui", "hammer" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", "����һö�ɺ��׽�ĸ������ɵĴ󴸣�����ȥ��\n"
			    "��ӯӯ, �Եü��ǳ��ء�\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N���һ��, �ճ�һö���ص�$n��\n");
                set("unwield_msg", "$N�����е�$n�����ջء�\n");
        }
        init_hammer(40);
        setup();
}

