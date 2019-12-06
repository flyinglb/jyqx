// Room: /d/village/eroad3.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ���������һ�����������ʯ·����������
�������ĵĴ�ȳ��ˣ�������һ���������ӣ������Ǽ��ӻ��ꡣ
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"shop",
            "south" : __DIR__"smithy1",
            "east"  : __DIR__"eroad2.c",
            "west"  : __DIR__"square",
        ]));
        set("objects", ([
            __DIR__"npc/girl": 1
        ]) );
//        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
        replace_program(ROOM);
}

