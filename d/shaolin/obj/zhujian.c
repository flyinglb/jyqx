// zhujian.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��",({ "zhu jian", "jian", "sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "bamboo");
		set("long", "����һ�����������������Ƴɵ����񽣣��䲻������ȴ�����ˡ�\n");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(10);
	setup();
}
