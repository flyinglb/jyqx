// Room: /d/gaochang/room60.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
ɽ�ϻ�ѩ���񣬵�·��᫣��������Ƿ�����ת������ɽ�£�����һ�������֡�
�������������������������֦�½��ᣬ������ѹ�����ߺ�İ�ѩ����������ѩ
�٣��������ߡ�
LONG
);
	set("no_new_clean_up", 0);
	set("outdoors", "room60");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhang" : 3,
]));
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room59",
  "west" : __DIR__"room61",
]));

	setup();
	replace_program(ROOM);
}
