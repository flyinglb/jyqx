// kandao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("����", ({ "kan dao", "dao", "blade" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ֱܴ��Ŀ�������ſ������񻹴պϡ�\n");
		set("value", 10);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(5);
	setup();
}
