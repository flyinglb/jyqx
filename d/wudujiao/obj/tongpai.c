#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_read","see");
}

void create()
{
	       set_name("ͭ��", ({"tongpai" }));
	
		set("unit", "��");
		set("long", "����һ�����ķ�����ͭ��,�������:��ǧ���򶾡��ĸ����֡�\n
ͭ�Ʊ���������һЩϸϸ�Ļ��ƣ���Ҫ��ϸ��(see)������ǿ�������\n");
		set("value", 0);
              set("no_drop", "�������������뿪�㡣\n");
              set_weight(200);

	
	setup();
}

int do_read(string arg)
{
	return notify_fail("                           \n
                                    ^                 \n
                                 @@^ ^     ^          \n                
                                  ^ ^ ^   ^ ^ @@@     \n 
                               @@@@^ ^ ^ ^ ^ ^        \n  
                                ^ ^ ^ ^ ^ ^ ^ ^       \n
                               ^ ^ ^ ^ ^ ^ ^ ^ ^       \n
                              ^ ^ ^ ^O^ ^O^ ^O^ ^       \n
                             ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^       \n
                            ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^      \n
                           ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^    \n
");
}

