//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��԰");
	set("long", @LONG
�����������˼���լ�к�԰��һ�ǣ���������������Ļ��ݣ������޷�
���⻨�ݴ����ҵ������ߵ�·���������ܿ����ĳ��˻���֮�⣬ֻ��һ��ǽ��
��������ǽ���ϵ�һ������(window)�����ӵ��Ǳ�Ӧ������õ��Է���
LONG );
	set("objects", ([
		__DIR__"obj/lingzhilan" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","kunlun");
	setup();
}
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me;
	me = this_player();
	if (!arg || arg != "window") 
	return 1;
	message_vision("$N�Ӵ������˽�ȥ��\n", me);
	me->move(__DIR__"cefang");
	message_vision("$N�Ӵ������˽�����\n", me);
	return 1;
}
