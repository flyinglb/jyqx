// zhenzhu.c ���� 
#include <armor.h>
 
inherit CLOTH;
 
void create()
{
	set_name("������", ({ "zhenzhu" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("long", "����һ�������飬��ֵǮ��\n");
		set("value", 30000);
		set("armor_prop/dodge", 5);
	}
	setup();
}
