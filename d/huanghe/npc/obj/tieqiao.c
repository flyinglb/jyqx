// tieqiao.c

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("����", ({ "tie qiao", "qiao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ڿ�����¡�\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��غ�����\n");
	}
	init_club(2);
	setup();
}

