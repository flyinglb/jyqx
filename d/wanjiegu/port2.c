// Room: /t/wanjiegu/port2.c

inherit ROOM;

void create()
{
        set("short", "���׽���");
        set("long", @LONG
������һ��Сɽ�£���������ɽ��·������һ�������ź�罭
�棬ֻ����ˮ���ڣ���Х���������紵�������Ż�����ȥ��
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "westup" : __DIR__"slide3",
            "east" : __DIR__"bridge",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
