// Room: /u/mei/room6.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
山路自东向西，地势渐平。云中有几头苍鹰在低低的盘旋遨翔，仿佛
将行人当作了猎物。路面铺着小石子，道两旁的灌木越来越少，骄阳似火，
令人真想找个地方休息一下。
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
