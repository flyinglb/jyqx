// xiaren.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(WHT"���Ϻ��"NOR, ({ "lingbai xiaren", "xiaren" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������������ڵ����Ϻ�ʡ�\n");
		set("unit", "��");
		set("value", 180);
		set("food_remaining", 8);
		set("food_supply", 20);
		set("material", "meat");
	}
	setup();
}

