// ROOM: /xiakedao/shidong1.c
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯ����Ҳ��֪���˶�ã�ֻ��Խ��Խ�ͣ����г�����
��ˮ֮������������������ö���������ࡣ
LONG );
        set("exits", ([
               "east" : __DIR__"dongmen",
               "north" : __DIR__"yongdao2",
               "south" : __DIR__"shidong6",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
