// road3.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "����·");
	set("long", @LONG
������һ������·�ϡ�������ȥ���������Կ���ƽ���ݡ���
���������ǿ쵽�ˡ�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "east" : "/d/city2/ximenwai",
                "west" : __DIR__"pingdingzhou",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
