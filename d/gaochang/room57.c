// Room: /u/mei/room57.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
���ܹ������죬�����ܲ���Ũ�ܿ�����Ҷ�ڱ��������ǳ���ʹ�˷ֲ�����
ҹ����������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"room58",
  "eastdown" : __DIR__"room56",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room57");

	setup();
	replace_program(ROOM);
}
