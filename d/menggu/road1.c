// Room: /d/menggu/road.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
����һ���̻���ɽ���·����������ɽ����������ͷ��
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "southeast" : "/d/city2/beimenwai",
                "northwest" : "/d/menggu/road2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
