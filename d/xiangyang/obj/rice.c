// rice.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIR"�����׷�"NOR, ({ "rice", "mi fan" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ĸ����׷���\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 10);
		set("material", "rice");
	}
	setup();
}

