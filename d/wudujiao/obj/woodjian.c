// musword.c ľ��

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("ľ��", ({ "woodjian", "jian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������õ�ľ������ͷ��ƽ�ġ�\n");
		set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(5);
	setup();
}
