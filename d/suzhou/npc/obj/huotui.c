// huotui.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(RED"ӣ�һ���"NOR, ({ "yingtao huotui", "huotui" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������������ڵ�ӣ�һ��ȡ�\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 10);
		set("food_supply", 20);
		set("material", "meat");
	}
	setup();
}

