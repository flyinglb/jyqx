
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name(HIW"����"NOR ,({ "yin lun","lun","yinlun" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",HIW"����һ�����������ķ��֡�\n"NOR);
		set("value", 10000);
		set("material", "silver");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg","$N�����е�$n�Ż����䡣\n");
	}
	init_hammer(150);
	setup();
}
