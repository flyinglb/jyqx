// gunny_shoes.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("��Ь", ({ "gunny shoes", "shoes" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", 
"����һ˫�鲼Ь�����״󻬣������˵�ɽʹ�á�\n");
		set("value", 150);
		set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/armor", 1);
	}

}
