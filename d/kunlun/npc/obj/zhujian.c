// zhujian.c 
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��", ({ "zhu jian","jian","sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ���񽣽���һ�����������ϰ�书�õġ�\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������\n");
	}
	init_sword(5);
	setup();
}
