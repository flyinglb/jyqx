#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIC"ǧ�����"NOR, ({ "bingcan" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "paper");
            set("dynamic_quest", "/kungfu/class/xingxiu/azi");
	}
}
