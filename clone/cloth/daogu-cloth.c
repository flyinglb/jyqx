// daogu-cloth.c �������

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"�������"NOR, ({"pao", "cloth", "dao pao"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("long", "һ������ͨͨ�Ļ�����ۡ�\n");
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	setup();
}
