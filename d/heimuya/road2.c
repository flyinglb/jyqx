// road2.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "����·");
	set("long", @LONG
������һ������·�ϡ�������һ��С�߸ڣ������ն񣬿���
�Ͼ��������������Կ���ƽ���ݳǡ�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "southwest" : __DIR__"road1",
            "east" : __DIR__"pingdingzhou",
            "west" : "/d/gaochang/room1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
