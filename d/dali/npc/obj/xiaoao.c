// xiaoao.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("Բ��С��", ({ "xiao ao", "cloth" }));
	set("long", "����һ��̨�����Բ��С����\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 300);
		set("armor_prop/armor", 1);
	}
	setup();
}
