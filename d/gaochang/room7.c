// Room: /u/mei/room7.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "ɳ��С��");
	set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١���������
����綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���
һ����һ���������۵�С���������Ͷ�����չ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room8",
  "eastup" : __DIR__"room6",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room7");

	setup();
	replace_program(ROOM);
}
