// Room: /t/wanjiegu/shan_road2.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ��ɽ��С·������ɽ�������������ľ�����紵������
��ɳɳ��������·����������Ӳݣ�������������������߶���
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"shan_road3",
            "eastdown" : __DIR__"shan_road1",
        ]));
        set("objects", ([
            __DIR__"npc/bee" : 2,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
