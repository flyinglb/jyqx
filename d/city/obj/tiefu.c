// gangjian.c

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("��ͷ", ({ "fu tou", "axe" }));
        set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�ѿ����õĸ�ͷ��������������˵㡣\n");
                set("value", 500);
		set("material", "steel");
                set("wield_msg", "$N�Ӻ����γ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���������档\n");
	}
        init_axe(10,0);
	setup();
}
