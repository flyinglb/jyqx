// Room: /u/mei/room6.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·�Զ����������ƽ�ƽ�������м�ͷ��ӥ�ڵ͵͵��������裬�·�
�����˵��������·������Сʯ�ӣ������ԵĹ�ľԽ��Խ�٣������ƻ�
���������Ҹ��ط���Ϣһ�¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room7",
  "eastdown" : __DIR__"room5",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room6");

	setup();
	replace_program(ROOM);
}
