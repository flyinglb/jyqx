// Room: /u/mei/room45.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��ԭ����һ����ɽ�������������������ɽ����ȫ�ǰ�����ѩ��ɽ������
ȴ�����Դ���ľ��һʱ�ڴ�Ŀ�ɣ���ҡ��ۡ�ֻ������С����ౣ����б���ײ����
���ٲ�����֯��һƬ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room46",
  "east" : __DIR__"room44",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room45");

	setup();
	replace_program(ROOM);
}
