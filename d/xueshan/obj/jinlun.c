
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name( HIY  "����" NOR,({ "jin lun" ,"lun" ,"jinlun" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",HIY"����һ����������ķ��֡�\n" NOR);
		set("value", 10000);
		set("material", "gold");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg","$N�����е�$n�Ż����䡣\n");
	}
	init_hammer(200);
	setup();
}
