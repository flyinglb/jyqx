// Room: /u/mei/room48.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������һ����·�����۵�ͨ��һ����ɭ��Ĵ��֣���·��᫿�����
������紵��������ʪ�ĳ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room49",
  "east" : __DIR__"room47",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room48");

	setup();
	replace_program(ROOM);
}
