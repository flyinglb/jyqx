// gangzhang.c ����

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("����", ({ "gangzhang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����صĸ��ȣ���������ר��֮�\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_staff(25);
	setup();
}
