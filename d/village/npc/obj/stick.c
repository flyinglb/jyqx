// stick.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("����", ({ "walking stick", "stick" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ɽ�õ����ȡ�\n");
		set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(5);
	setup();
}
