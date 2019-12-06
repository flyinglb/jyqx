
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("¸Ö¼×", ({ "gang-jia", "jia", "armor" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "steel");
		set("value", 2000);
		set("armor_prop/armor", 200);
	}
	setup();
}

