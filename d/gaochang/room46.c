// Room: /u/mei/room46.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�������棬������ˮ��΢΢����һ����������Ȼ���Ǳߴ����˽��������ĸ�
����
    ��������·�Ĵ���������
          Ϊ��ô�ӵÿ죿�ڲ�����
          �˼�ϴ������͵����������Ӵ�������Ĵ󵨸ò��ã���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room45",
  "west" : __DIR__"room47",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room46");

	setup();
	replace_program(ROOM);
}
