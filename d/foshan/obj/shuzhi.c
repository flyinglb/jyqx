// shuzhi.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(GRN"С��֦"NOR, ({ "shu zhi"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��С��֦��\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_staff(1);
	setup();
}
