// tiebian.c ����

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("����", ({ "changbian", "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ִ�����ޣ�������ʮ�����ء�\n");
		set("value", 100);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(40);
	setup();
}
