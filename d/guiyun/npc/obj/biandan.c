// biandan.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("�����ⵣ", ({ "bian dan" }));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "ͨ������͵أ��м�΢�䣬��ͷ����һ��ͻ������ӡ�\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_staff(15);
	setup();
}
