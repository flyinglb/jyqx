// jinfenggou.c ��
// by star 98.12.4
#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
	set_name(HIY"��"NOR, ({ "jinfeng gou", "gou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ι�˾綾�Ľ𹳣����˺���һֻ��ͷ��\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������С�\n");
	}
	init_sword(200);
	setup();
}
