// fuchen.c ����

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("����", ({ "fu chen", "fu" ,"chen"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�ķ�����\n");
		set("value", 100);
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(30);
	setup();
}
