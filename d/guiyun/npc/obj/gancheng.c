// gancheng.c

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("�˳�", ({ "gan cheng" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����л��ﳣ�õĸ˳ӡ�\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_club(5);
	setup();
}
