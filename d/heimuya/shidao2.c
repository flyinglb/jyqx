// shidao1.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ·�����½̽��ڰ������ܣ���������ɽ��������һ��ˮ̲
֮ǰ��������һ��ʯ��ͨ��ˮ̲��
LONG    );
        set("outdoors", "heimuya");
        set("exits", ([
            "westdown" : __DIR__"xingxingtan",
            "south" : __DIR__"shidao1",
        ]));
        set("objects", ([
            __DIR__"npc/wangcheng" : 1,
            __DIR__"npc/heiyiren" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
