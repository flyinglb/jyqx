// tiedi.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIB"����"NOR, ({"tie di"}));
	set_weight(500);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "һ֧�������ɵĳ��ѣ�����ȥ�����쳣��\n");
		set("value", 10000);
		set("material", "bamboo");
		set("wield_msg", "$N����һ�ӣ������Ѷ���һ֧�ں��͹�����ѡ�\n");
		set("unwield_msg", "$N��������һת��գ�ۼ�������Ȼ����Ӱ�١�\n");
	}
	init_sword(50);
	setup();
}
