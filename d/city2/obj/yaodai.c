// yaodai.c

#include <armor.h>

inherit WAIST;

void create()
{
	set_name("����", ({ "waist band","waist","band" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "leather");
		set("armor_prop/armor", 3);
		set("female_only", 1);
	}
	setup();
}

