// huwan.c ����

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( "����", ({ "wrists", "hu wan", "huwan" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "����һ�����ʵĻ������Ա����󲿡�\n");
		set("value", 1300);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}
