// Room: /d/xingxiu/xxroad7.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����᫵�С·�ϣ�����������̣�����������
LONG );
        set("exits", ([
            "southeast" : __DIR__"xxroad6",
            "west" : __DIR__"xxroad8"
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
