// huoqiang.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("������ǹ", ({"helan huoqiang", "huoqiang"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "һ֧������ǹ����ϧֻ�ܷ�һǹ��\n");
		set("value", 10000);
		set("material", "bamboo");
		set("wield_msg", "$N���һ֧���͵�ľ����ǹ�������С�\n");
		set("unwield_msg", "$N�����еĻ�ǹ���ر��ϡ�\n");
	}
	init_staff(30);
	setup();
}
