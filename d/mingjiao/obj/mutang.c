//yitianjian.c
#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("ľ��", ({ "mu tang", "mu","tang" }) );
    set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 50);
        	set("material", "wood");
        	set("long", "����һ��������õ�ľ�ۡ�\n");
        	set("wield_msg","$N�߸߾���$n��\n");
        	set("unwield_msg", "$N����$n����Щ����������\n");
	}
    	init_blade(20);
	setup();
}
