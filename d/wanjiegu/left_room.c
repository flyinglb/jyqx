// Room: /t/wanjiegu/left_room.c

inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
����һ����ͨ�ķ��䣬�������һЩ�ճ���Ʒ�������Ϸ���һ
���裬��û��������Ա�һ������ӣ������������·���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"bed_room",
            "east" : __DIR__"hall",
        ]));

        set("objects", ([
            __DIR__"npc/xier" : 1,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
