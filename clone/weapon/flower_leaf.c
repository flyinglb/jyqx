// flower_leaf.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
	set_name("����", ({ "flower leaf", "hua ban", "ban" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ʵ�õ�廨�Ļ��꣬���滹���⾧Ө��¶�顣\n");
		set("unit", "��");
		set("value", 0);
		set("base_unit", "Ƭ");
		set("base_weight", 1);
		set("base_value", 0);
		set("damage", 2);	//Here the damage=int_throwing, added by King
	}
	set_amount(50);
	init_throwing(2);
	setup();
}
