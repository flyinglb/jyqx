// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�ֵ�", ({ "blade" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λεĸֵ�����ͨ�ٱ��ĳ���������\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(20);
	setup();
}
