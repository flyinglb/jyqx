// jiedao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("�䵶", ({ "jie dao", "dao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("long", "����һ���߰볤�Ľ䵶���������������ֳ��أ����Ǿ�����ɡ�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("shaolin",1);
	}
	init_blade(25);
	setup();
}
