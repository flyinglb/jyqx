// majia.c

#include <armor.h>
#include <ansi.h>

inherit WAIST;

void create()
{
	set_name(HIM "С���" NOR, ({ "waist coat","waist","coat" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\n����������ؼס��ۺ�ɫ��С��������ż�ֻԧ�죬����������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 50000);
		set("material", "˿");
		set("armor_prop/armor", 3);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

