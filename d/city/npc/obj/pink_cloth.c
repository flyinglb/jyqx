// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ۺ����", ({ "pink cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ۺ�ɫ�ĳ����������ż�ֻ��ȵ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

