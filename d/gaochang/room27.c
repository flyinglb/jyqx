// Room: /u/mei/room27.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
��ط��Ǹ���أ����ܸ�ɽ���������·��겻�֣�ǧ����֮�����������
�ã�ʵ�Ǻ������ţ���·ֻ����ذ׹ǣ���ǹ��ꪣ������Ҷ������е�·Ҳ��
�������Թ��������ۻ����ҡ�
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "room27");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room26",
  "north" : __DIR__"room29",
]));

	setup();
	replace_program(ROOM);
}
