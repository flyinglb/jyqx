// dafu.c

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
	set_name("��", ({"da fu", "axe"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ʮ�ַ����Ĵ󸫡�\n");
		set("value", 100);
		set("material", "bamboo");
		set("wield_msg", "$N���ִ������һ���󸫡�\n");
		set("unwield_msg", "$N������һ�𣬰Ѵ󸫲��ں����ϡ�\n");
	}
	init_axe(50);
	setup();
}
