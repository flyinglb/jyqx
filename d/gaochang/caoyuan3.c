// Room: /u/mei/caoyuan3.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "��ԭ");
	set("long", @LONG
����һƬ�ޱ��޼ʵĲ�ԭ�����˸ߵ���������������罭���е��㣬����
����֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,������Ȼ���¡� 
LONG
	);
	set("outdoors", "caoyuan3");
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan4",
  "east" : __DIR__"caoyuan2",
]));

	setup();
	replace_program(ROOM);
}
