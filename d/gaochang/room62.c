// Room: /u/mei/room62.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��ããɽ����һƬ��ѩ�����²������ˣ�ɽ�ƽ�����ѩ���ú��ģ�ת����
��ɽ�꣬ɽ�������վ�����ľ������ɽʯ��ᾣ��������ǲ��㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"room61",
  "southdown" : __DIR__"room63",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room62");

	setup();
	replace_program(ROOM);
}
