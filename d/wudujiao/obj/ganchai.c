#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_make","zha");
	add_action("do_make","make");
}

void create()
{
	       set_name("�ɲ�", ({"ganchai" ,"chai"}));
	
		set("unit", "��");
		set("long", "����һС���ջ��õĸɲ�\n");
		set("value", 0);
//            set("no_drop", "�������������뿪�㡣\n");
              set_weight(500);

	
	setup();
}

int do_make(string arg)
{
    object me = this_player();
    object ob = this_object();
    if ((ob->query("name"))=="���")
    return 0;
    if (arg != "���" && arg !="huoba")
    return 0;
    message_vision ("$N����һ���ɲ��������¾�������һ֧��ѡ�\n\n",me);
    this_object()->recreate();
    return 1;
}
void recreate ()
{
	       set_name("���", ({"huo ba","ba"}));
	
		set("unit", "֧");
		set("long", "����һ֧�����õĻ�ѡ�\n");
		set("value", 0);
//            set("no_drop", "�������������뿪�㡣\n");
              set_weight(300);
	setup();
}

