// mudao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("ľ��", ({ "mu dao", "dao", "blade" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("long", "����һ��ľ�ƵĶ̵���������ɮϰ����ô˵����������ˡ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
		set("shaolin",1);
	}
	init_blade(5);
	setup();
}
