// female-shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIM"�廨СЬ"NOR, ({ "flower shoes", "shoes"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
		set("long", "һ˫Ů�˴��ķ��Ƶúܾ������廨Ь��\n");
		set("value", 0);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}
