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
	       set_name("Ы�Ӷ���", ({"xiezi dunang" ,"dunang"}));
	
		set("unit", "��");
		set("long", "����һ��Ы�ӵĶ��ҡ�\n");
		set("value", 100);
//            set("no_drop", "�������������뿪�㡣\n");
              set_weight(100);

	
	setup();
}

int do_eat(string arg)
{
    object me = this_player();
//    object ob = this_object();
    if (arg != "xiezi dunang" && arg !="dunang")
    return 0;
    tell_object(me,  "������������suicide�ȽϿ�һ�㡣\n" );
    return 1;
}
