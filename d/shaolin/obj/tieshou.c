// tieshou.c

#include <armor.h>

inherit HANDS;

void create()
{
	set_name( "������", ({ "iron hand", "hand" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "��");
		set("value", 5);
		set("armor_prop/armor", 1 );
	}
	setup();
}
