#include <weapon.h>
inherit WHIP;

void create()
{
	set_name( HIG "��Ȯ��" NOR, ({ "cequanbian", "bian" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����е��̵ĳ��ޣ���ţƤ�;�����֯���ɡ�\n");
		set("value", 10000);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(50);
	setup();
}
