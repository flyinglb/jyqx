// bi.c

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(HIC"�йٱ�"NOR, ({ "pangguan bi" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֦");
		set("long", "����һ֦������͵��йٱʡ�\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N����һ֦$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������\n");
	}
  	init_dagger(20);
	setup();
}

