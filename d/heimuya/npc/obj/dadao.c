#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��", ({ "da dao", "dao" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1500);
		set("material", "iron");
		set("long", "����һ������Ĵ󵶡�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(10);
	setup();
}
