// Room: /u/mei/room3.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ƾɳ���");
	set("long", @LONG
������ΰ�ĳ�������Ŀȫ�ǣ����º�ս���Ѽ���������Ϊƽ�ء�Ψһ��
���һ����棬��������Ӣ�۵���ѪȾ�ɰ���ɫ��������Ȼ��һƬ��ɱ��ȴ
�м���С������ʯ�ķ�϶�м�����������һ�������ĸо���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room4",
  "east" : __DIR__"room2",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room3");

	setup();
	replace_program(ROOM);
}
