//shigu.c
#include <weapon.h>

inherit HAMMER;

void create()
{
    set_name("ʬ��", ({ "shi gu", "shi","gu" }) );
    set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "ֻ");
        	set("value", 50);
        	set("material", "wood");
        	set("long", "����һֻ��ɭɭ��ʬ�ǡ�\n");
        	set("wield_msg","$N������סһ��$n������¶����а��Ц�⡣\n");
        	set("unwield_msg", "$N��$n������䣬��ɫ��ʱҲ�ָ���������\n");
	}
    	init_hammer(100);
	setup();
}
