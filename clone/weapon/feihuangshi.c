// feihuangshi.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
	set_name("�ɻ�ʯ", ({ "feihuangshi", "shi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��ϸ��ѡ�Ķ���ʯ����Сһ�£�������������Բ��\n");
		set("unit", "��");
		set("value", 0);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 0);
		set("damage", 5);	//Here the damage=int_throwing, added by King
	}
	set_amount(20);
	init_throwing(5);
	setup();
}
