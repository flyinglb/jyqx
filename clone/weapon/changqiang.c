// changqiang.c ��ǹ

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("��ǹ", ({ "changqiang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ӧ����ǹ�������ɶ���ǹͷ����͸�����⡣\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N����һ�˸�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������\n");
	}
  	init_club(25);
	setup();
}

