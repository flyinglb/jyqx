// kenao.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("խ�̰�", ({ "ken ao" }));
	set("long", "����һ���������峣�õ�խ�̰���\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 400);
		set("armor_prop/armor", 5);
	}
	setup();
}
