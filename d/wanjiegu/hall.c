// Room: /t/wanjiegu/hall.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������һ�Ŵ����ӣ���ǽ�����ŵ��ӣ��װ׵�ǽ��һ����Ⱦ
����һ������������������ȥ���Ե����齹�١�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"backyard",
            "west" : __DIR__"left_room",
            "south" : __DIR__"xiaoting",
            "east" : __DIR__"right_room",
        ]));
        set("objects", ([
            __DIR__"npc/zhong" : 1,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
