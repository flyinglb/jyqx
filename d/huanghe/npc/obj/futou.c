// futou.c

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("��ͷ", ({ "futou", "da futou" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ���Ĵ�ͷ��\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��غ�����\n");
	}
	init_axe(5);
	setup();
}

