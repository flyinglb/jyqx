// mujian.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("ľ��", ({ "mu jian", "sword", "jian" }));
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
	init_sword(3);
	setup();
}
