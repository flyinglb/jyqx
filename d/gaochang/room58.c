// Room: /u/mei/room58.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
ֻ���Ѵ�����һ��ѩ��Ĵ���֮�ڡ�ֻ��һ���޼ʵ�ѩ�������ų�����һ��
��ӡ������ຮ��ɽ����ѩδ�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room59",
  "southdown" : __DIR__"room57",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room58");

	setup();
	replace_program(ROOM);
}
