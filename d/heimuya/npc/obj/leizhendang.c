// leizhendang.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("����", ({"leizhen dang", "staff"}));
	set_weight(8000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ʮ�ֳ��ص����𵲡�\n");
		set("value", 10000);
		set("material", "bamboo");
		set("wield_msg", "$N���ִ������һ�����𵲡�\n");
		set("unwield_msg", "$N������һ�ۣ������𵲷������\n");
	}
	init_staff(50);
	setup();
}
