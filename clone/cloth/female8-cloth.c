// female8-cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(MAG"��ɴС����"NOR, ({ "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���Ǽ���ɴС������\n");
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

