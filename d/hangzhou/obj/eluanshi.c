// eluanshi.c

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
	set_name(HIC"����ʯ"NOR, ({ "eluan shi", "shi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
		set("long", "����һ��ƽƽ�����Ķ���ʯ��\n");
                set("base_unit", "��");
                set("base_weight", 300);
		set("value", 0);
		set("material", "stone");
		set("wield_msg", "$N�ͳ�һ��$n׼��ս����\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
        set_amount(10);
	init_throwing(1);
	setup();
}
