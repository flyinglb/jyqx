// Room: /d/gaochang/caoyuan2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
����һƬ�ޱ��޼ʵĲ�ԭ�����˸ߵ���������������罭���е��㣬����
����֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,������Ȼ���¡� 
LONG
);
	set("no_new_clean_up", 0);
	set("outdoors", "caoyuan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yanshu" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan3",
  "north" : __DIR__"caoyuan1",
]));

	setup();
	replace_program(ROOM);
}
