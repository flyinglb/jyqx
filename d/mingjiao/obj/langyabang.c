#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("������", ({ "langya bang", "bang" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͷ��������Լ��������Ǽ����ֵ��ر�����\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
		set("shaolin",1);
        }
        init_staff(200);
        setup();
}

