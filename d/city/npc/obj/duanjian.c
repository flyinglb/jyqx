// shortsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�̽�", ({ "duanjian", "jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������С�ľ��ֽ���һ��Ľ��Ͷ�����˽���\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(15);
	setup();
}
