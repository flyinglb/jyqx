// tiechui.c ������

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("������", ({ "tiechui", "chui","hammer" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����صĴ�������������ų�����������\n");
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N����ॡ���һ��,ȡ��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�һ����䡣\n");
	}
	init_hammer(50);
	setup();
}
