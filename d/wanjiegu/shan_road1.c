// Room: /t/wanjiegu/shan_road1.c

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
            "westup" : __DIR__"shan_road2",
            "northdown" : __DIR__"slide3",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
