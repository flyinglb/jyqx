// card2.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"�׻���"+HIY+"����"NOR, ({"card2"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"������������µڶ����ð׻�������,�������һֻ�׻���\n");
	set("unit", "��");
	set("weight", 10);
}
}
int query_autoload() { return 1; }

