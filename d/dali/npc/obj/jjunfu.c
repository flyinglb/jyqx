// jjunfu.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("���¾���", ({ "junfu", "cloth" }));
	set("long", "����һ����ɫ�����Ľ��¾�����\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 1200);
		set("armor_prop/armor", 15);
	}
	setup();
}
