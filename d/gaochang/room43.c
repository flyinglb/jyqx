// Room: /u/mei/room43.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
Ϫˮת���ƹ�һ��ߵأ���Ȼ��ǰһƬ���٣�ˮ����䲻����ƥ����������
���������齦�񣬶ٳ���ۡ���������Ĵ�Į֮��ͻȻ�������������������ˬ��
���������뿴���ٲ�֮�ϸ�����ô��ɫ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room44",
  "south" : __DIR__"room42",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room43");

	setup();
	replace_program(ROOM);
}
