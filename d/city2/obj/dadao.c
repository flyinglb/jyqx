// dadao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("��", ({ "dadao","blade" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λεĴ󵶡�\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ���ӱ��󲦳�һ��$n��\n");
		set("unwield_msg", "$N�����е�$n��ر���\n");
	}
	init_blade(40);
	setup();
}
