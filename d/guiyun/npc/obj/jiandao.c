// jiandao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�⵶", ({ "jian dao", "blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ɱ����\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_blade(10);
	setup();
}
