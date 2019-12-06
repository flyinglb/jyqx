#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(RED "ÑªÀÇ" NOR, ({ "blade","wolf blade" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "Ë«");
		set("value", 1);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}
