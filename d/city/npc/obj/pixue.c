// boots.c Ƥѥ
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("Ƥѥ", ({ "boots", "pi xue", "xue" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "˫");
		set("long", "����һ˫���Ϻ�ţƤ����Ƥѥ����˵���Ϻ����ڡ����Ա����㲿��\n");
		set("value", 1000);
		set("armor_prop/dodge", 8);
	}
	setup();
}