#include <ansi.h>

inherit ITEM;
void dest();



void init()
{
       remove_call_out("dest");
       call_out("dest", 100);
}

void create()
{
	set_name("�ù��İٻ����߸�", ({"usedgao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ù��İٻ����߸ࡣ\n");
		set("value", 1000);
		set("no_drop", "�������������뿪��!\n");
	}
	setup();
}


void dest()
{
    destruct(this_object());
}

