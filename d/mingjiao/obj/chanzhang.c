#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("����", ({ "chan zhang", "zhang" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������������ȣ�Լ��ʮ����Ǽ����ֵ��ر�����\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
		set("shaolin",1);
        }
        init_staff(25);
        setup();
}

