// Room: /u/mei/room59.c// This is a room made by roommaker. write by Fan. :)
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
  "westup" : __DIR__"room60",
  "eastdown" : __DIR__"room58",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room59");

	setup();
	replace_program(ROOM);
}
