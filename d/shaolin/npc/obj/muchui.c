// mudao.c

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("ľ���", ({ "muyu chui", "chui" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50);
		set("material", "wood");
		set("long", "����һ�Ѻ������ľ���õ�Сľ鳡�\n");
		set("wield_msg", "$N���´����ͳ�һ��$n���������е�������\n");
		set("unequip_msg", "$N�����е�$n�Ż��´���\n");
		set("shaolin",1);
	}
	init_hammer(1);
	setup();
}
