#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "��֬��" NOR, ({"lingzhilan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "����һ֧���ж��������֬����\n");
		set("value", 0);
	}
	setup();
}
