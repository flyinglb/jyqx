// mudao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ľ��", ({ "mu dao", "blade", "dao" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ľ������ľ�����ֹ��൱��ϸ��\n");
		set("value", 50);
		set("material", "steel");
		set("wield_msg", "$N����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ϡ�\n");
	}
	init_blade(3);
	setup();
}
