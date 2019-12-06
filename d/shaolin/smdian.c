// Room: /d/shaolin/smdian.c
// Date: YZC 96/01/19

inherit ROOM;

void init();
void close_gate();
int do_close(string arg);
string look_gate();
int do_open(string arg);

void create()
{
	set("short", "ɽ�ŵ�");
	set("long", @LONG
�����������µ�ǰ��ɽ�ŵ������ש�̵أ�������кߡ�
��������������ΰ�������ŭ��ͷ�����ڣ��ϰ�����¶����ִ
����ƣ�һ�ıǣ�һ�ſڣ�¶����Ŀ�����Ϳ�η�����߸���һ
��ľ���������������Թ�ɮ��ߵ�ݡ��Դ����Ҹ���һ��ƫ�
�������Ǵ����о�֮�á�������һ���������ߵ����ɼľ��ͭ
����(gate)��
LONG );
	set("exits", ([
		"east" : __DIR__"smdian1",
		"west" : __DIR__"smdian2",
		"north" : __DIR__"taijie",
	]));
	set("item_desc",([
		"gate"		:	(: look_gate :),
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
		__DIR__"npc/xiang-ke" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"guangchang1")) )
		room = load_object(__DIR__"guangchang1");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "ɮ����ǰ�Ѵ��Ź���������\n", this_object());
		room->delete("exits/north");
		message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$N��ɮ�����˵�ͷ��\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);

	return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"guangchang1")) )
		room = load_object(__DIR__"guangchang1");
	if(objectp(room))
	{
		set("exits/south", __DIR__"guangchang1");
		message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

string look_gate()
{
	return "һ���������ߵ����ɼľ��ͭ���š�\n";
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;

	return ::valid_leave(me, dir);
}

