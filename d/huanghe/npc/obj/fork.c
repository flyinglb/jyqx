// fork.c

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("���ɲ�", ({ "sangu cha" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����⿪�е����ɲ档\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������\n");
	}
  	init_club(15);
	setup();
}

