// jinshechui.c ���ߴ�

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("���ߴ�", ({ "jinshe chui", "chui","hammer" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����������Ĵ��������εĴ�������������ų�����������\n");
		set("value", 3000);
		set("material", "steel");
		set("wield_msg", "$N����ॡ���һ��,ȡ��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�һ����䡣\n");
	}
	init_hammer(800);
	setup();
}
