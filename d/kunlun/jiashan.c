//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��԰һ��");
	set("long", @LONG
���ǻ�԰�������ߵĵط�������Զ����ׯ�ӿ���ԶԶ����ɽ���ơ�����
С�µ���ߵ㣬������һ���ܶ�Ź�ʯͷ����ļ�ɽ���ڼ�ɽ��һ�����ϣ���
һ���ʯ�е��ر𣬲�֪���ǲ��ǿ�����(move)�ÿ���
LONG );
	set("exits", ([
		"northeast"  : __DIR__"hhyuan",
		"south" : __DIR__"huilang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{
	if(arg == "jiashan")
	{
		message_vision ("$N�����ƶ���ɽ�����ϳ���һ������\n", this_player());
		set("exits/down", __DIR__"dong8");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","���ƿ��ļ�ɽ�������ԭ�أ��Ѷ��������ˡ�\n", room);
	room->delete("exits/down");
}       

