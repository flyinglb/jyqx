// Room: /d/gaochang/room1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����ĵ�����һ�ֻƺ�ɫ�����ɫ��ʯ����Ƕ��ϸϸ�Ļ�ɳ֮�У�
�����Լ������ĸо������������������ԭ���м�ش�������������
������
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "east" : "/d/heimuya/road2",
]));
	set("outdoors", "room1");
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
