// Room: /u/mei/room52.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
Ͽ������ʯ�ڶ�Ȼ�����������õ����ɣ�̧ͷ���죬ֻ����ɫ������������
��Ǳ�ں�������һ�㡣Ͽ����ʯȫ�����ɫ���Ե��ڹⷢ������·������ȥ����
���쳣��Ͽ�ڳ��л�ѩ���ڰ���ӳ��εΪ��ۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room5",
  "east" : __DIR__"room51",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room52");

	setup();
	replace_program(ROOM);
}
