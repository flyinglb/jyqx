// mudao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("ľ��", ({ "mudao" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10);
		set("material", "iron");
		set("long", "����һС�����ľ����\n");
		set("wield_msg", "$N���һ����ƮƮ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(1);
	setup();
}
