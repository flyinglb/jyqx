#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIG"����"NOR, ({ "shoupa" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "paper");
		set("long","����һ���������ܵ��׷�������µġ�"NOR);
            set("dynamic_quest", "/d/npc/duanyanqing");
	}
}
