// Room: /u/mei/room42.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "СϪ");
	set("long", @LONG
������ҫ֮�У����������л���Ʈ����Ϫˮ���㣬���������л�֮�ʣ���Ϫ
ˮ��������ȥ������Ϫ������ɳĮ�еĺ���������ˮ�󣬵�����ʱˮ����
��ɳĮ���ɣ�������ʧ������Ϫ����ľҲ�������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room43",
  "south" : __DIR__"room41",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room42");

	setup();
	replace_program(ROOM);
}
