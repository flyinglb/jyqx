// axe.c

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("����", ({ "fu" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������õĶ̸����������м���ȱ�ڡ�\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_axe(5);
	setup();
}
