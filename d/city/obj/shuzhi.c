// shuzhi.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
    set_name(GRN"����֦"NOR, ({ "shu zhi"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����һ����ɽ�õ���֦��\n");
        set("value", 50);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(5);
	setup();
}
