// ring.c �����ָ

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIC "�����ָ" NOR, ({ "diamand ring", "diamand", "ring" }));
       	set("long", "���Ƿ���͸�����Ķ����ָ���������������裬�淢������ˡ�\n");
	set("weight", 200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("value", 100000);
		set("material", "��ʯ");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}	
