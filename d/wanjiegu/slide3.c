// Room: /t/wanjiegu/slide3.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ��֮������һЩ��֪�����Ӳݣ��Լ����������ֲ����Ĺ�
ľ�ԣ���������д���������Ұ����·�����Ŀ��ţ�ż���м�ֻ��
��������ȥ��
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "southup" : __DIR__"shan_road1",
            "eastdown" : __DIR__"port2",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
