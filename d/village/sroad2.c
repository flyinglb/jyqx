// Room: /d/village/sroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ���������һ���ϱ������ʯ·��������һ
��С������
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"sroad3",
            "south" : __DIR__"sroad1",
            "east"  : __DIR__"shouse",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
        replace_program(ROOM);
}

