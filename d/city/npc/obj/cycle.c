// necklace.c ������Ȧ
 
#include <armor.h>
 
inherit NECK;
 
void create()
{
	set_name("������Ȧ", ({ "neck-cycle", "xiang quan", "lian" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "��");
		set("long", "����һ�����ʵ����������Ա���������\n");
		set("value", 1800);
		set("armor_prop/dodge", 5);
	}
	setup();
}
