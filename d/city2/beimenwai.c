// Room: /d/city2/ximenwai.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����Ǳ����ı������⣬����ɽ������������Ѿ����ܶ��ˡ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"anding",
                "northwest" : "/d/menggu/road1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
