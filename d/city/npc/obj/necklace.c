// necklace.c ������

#include <armor.h>

inherit NECK;

void create()
{
	set_name("������", ({ "golden necklace", "necklace", "lace" }));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
