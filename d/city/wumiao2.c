// Room: /city/wumiao2.c
// YZC 1995/12/04 

#include <room.h>

#define BOARD_TOC "/doc/board/toc"
#define BOARD_DIR "/doc/board/"
inherit ROOM;
string look_shu();

void create()
{
	set("short", "�����¥");
	set("long", @LONG
������������Ķ�¥�����﹩�������ɵĳ������ƺ��������ܣ���������
���������Ӣ��������¥���Ǳ������������á�
    ���ſ���һ��С��������������һ���� (shu)����¼��������һ�������
��д�����������ȥ��һЩ���¡�����������Ķ�(yuedu)��
LONG );

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

        set("item_desc", ([
		"shu" : (: look_shu :),
	]));
//        set("objects", ([
//		"/clone/topten/topten": 1,
//	]));
	set("exits", ([
		"down" : __DIR__"wumiao",
		"up"   : __DIR__"mingren",
	]));
	setup();
}

void init()
{
        add_action("do_read", "yuedu");
}

string look_shu()
{
        this_player()->start_more(read_file(BOARD_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        if (arg == "" || file_size(BOARD_DIR + arg) <= 0)
                return notify_fail("����û����������Ү��\n");

        log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
        me->start_more(read_file(BOARD_DIR + arg));
        return 1;
}

