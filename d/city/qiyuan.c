// Room: /d/city/qiyuan.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ר��Ϊ�������ر���Ƶ������ҡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"duchang2",
]));
	set("objects", ([
		__DIR__"obj/cch" : 1,
	]));

	setup();
	replace_program(ROOM);
}
