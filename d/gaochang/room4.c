// Room: /u/mei/room4.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ�������߳�����Сɽ·����Ȼ����ȴ�ǹ�һ����ͨ�С�С·
˳��ɽ�н�Ϊƽ̹�ش�����������չ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room51",
  "eastup" : __DIR__"room3",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room4");

	setup();
	replace_program(ROOM);
}
