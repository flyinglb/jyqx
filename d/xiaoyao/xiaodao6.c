// Room: /d/xiaoyao/xiaodao6.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ң�ɵ��������ĵط�������������ľ�˷��ڵ��ϡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/mu-ren" : 5,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"xiaodao2",
]));

	setup();
	replace_program(ROOM);
}
