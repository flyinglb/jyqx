// Room: /u/mei/room8.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "��Į���");
	set("long", @LONG
���Ƶ����ǻ�Ȼ���ʣ����������һ���޼ʵ�ɳĮ������ں���������
��ɳ�ڷ��裬��ɳ������ɳ������������ϣ������ǲ��ŭͶ�µı�����ڤ
ڤ�з·�������а����������κ�����ʱ���п���ͻȻ��Ұ��������ɳ��
�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room9",
  "east" : __DIR__"room7",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room8");

	setup();
	replace_program(ROOM);
}
