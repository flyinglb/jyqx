//shebian.c
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("�߱�", ({ "she bian", "bian" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����Ƥ���ޡ�\n");
		set("value", 300);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(30);
	setup();
}
