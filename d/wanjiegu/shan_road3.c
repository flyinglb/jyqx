// Room: /t/wanjiegu/shan_road3.c

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
            "eastup" : __DIR__"shan_road2",
            "northdown" : __DIR__"shan_road4",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
