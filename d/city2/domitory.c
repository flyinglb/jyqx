// Room: /d/city2/domitory.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����û��һ����Ӱ�����ܶ�ȥ��MUD�ˡ�
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"Sino-CO",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
