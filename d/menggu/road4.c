// Room: /d/menggu/road.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
ɽ·�ƺ����˾�ͷ��������һƬһ���޼ʵĴ��ԭ��
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"road3",
                "north" : __DIR__"cy001",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
