// fenshuici.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("��ˮ��", ({ "fenshui ci", "ci" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һֻˮ�з�ˮ���Ҵ̡�\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һֻ$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������С�\n");
	}
	init_dagger(5);
	setup();
}

