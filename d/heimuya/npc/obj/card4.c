// card4.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"������"+HIY+"����"NOR, ({"card4"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"������������µ��Ĵ�������������,�������һ�����㡣\n");
	set("unit", "��");
	set("weight", 10);
}
}
int query_autoload() { return 1; }

