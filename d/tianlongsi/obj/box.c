#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("����", ({ "jin he", "he" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����װ�����ӵĺ���,���ƺ�Ӧ�ý���ʧ����\n");
		set("value", 1000);
		set("material", "wood");
	}
	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
//        object me, ob;
        object me;
	
	me = this_player();

	if(!arg&&arg!="he") return notify_fail("��Ҫ��ʲô������\n");
	message_vision("$N�򿪺��ӣ�ֻ����֧����������������������\n",me);
	message_vision("һ����ӰͻȻ���֣���$N����һ���������У������ȥ��\n",me);
        destruct(this_object());
	return 1;
}
