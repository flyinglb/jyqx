// Room: /d/menggu/road.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
����һ���̻���ɽ���·����������ɽ����������ͷ��
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"road2",
                "north" : __DIR__"road4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
