#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(WHT"���־�"NOR, ({ "baishoujuan" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "paper");
		set("long","����͸�С��Ů�����"NOR);
            set("dynamic_quest", "/d/gumu/longnv");
	}
}
