// ganggou.c �ֹ�

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�ֹ�", ({ "ganggou", "gou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ľ��ֽ������˴���һ��������\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������С�\n");
	}
	init_sword(25);
	setup();
}
