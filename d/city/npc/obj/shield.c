// shield.c ţƤ��
 
#include <armor.h>
 
inherit SHIELD;
 
void create()
{
	set_name("ţƤ��", ({ "leather shield", "shield", "dun" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("value", 1200);
		set("armor_prop/armor", 5);
		set("armor_prop/defense", 3);
	}
	setup();
}