#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat","eat");
}

void create()
{
	       set_name("���߶�Һ", ({"jinshe duye" ,"duye"}));
	
		set("unit", "ƿ");
		set("long", "����һƿ�綾�Ľ��߶�Һ��\n");
		set("value", 100);
//            set("no_drop", "�������������뿪�㡣\n");
              set_weight(100);

	
	setup();
}

int do_eat(string arg)
{
    object me = this_player();
//    object ob = this_object();
    if (arg != "jinshe duye" && arg !="duye")
    return 0;
    tell_object(me,  "������������suicide�ȽϿ�һ�㡣\n" );
    return 1;
}
