// Room: /u/mei/room56.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
������������������������б��·���ԵĹ�ľ����������ľ��Խ�ߵ���Խ��
�����ƣ������ڽ��£����ˣ�������ˮ����������һ������֮�����ƺ���Ư
�����ֲ�����ˮ�������Ǵ����ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room57",
  "eastdown" : __DIR__"room55",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room56");

	setup();
	replace_program(ROOM);
}
