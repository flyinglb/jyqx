// Room: /xiakedao/lin7.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ����֣������������һ����,һ�߽�������·���ʧ�˷���
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"lin6",
                "south" : __DIR__"lin8",
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northwest" : __FILE__,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
