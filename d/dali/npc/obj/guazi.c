// guazi.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("���ƹ���", ({ "duijin guazi" }));
	set("long", "����һ���������峣�õĶ��ƹ��ӡ�\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 350);
		set("armor_prop/armor", 5);
	}
	setup();
}
