// card1.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIB"������"+HIY+"����"NOR, ({"card1"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"������������µ�һ���÷���������,�������һ������\n");
	set("unit", "��");
	set("weight", 10);
}
}
int query_autoload() { return 1; }

