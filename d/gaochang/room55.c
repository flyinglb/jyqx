// Room: /u/mei/room55.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����Ĺ�ľ������Щ������ʹ��ֲ���ǰ���ĵ�·��һ��С�ľͱ���֦�ҵ�
���ֽţ���ǰ���ֲ�֪ͨ������㲻������������֮�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room56",
  "northdown" : __DIR__"room54",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room55");

	setup();
	replace_program(ROOM);
}
