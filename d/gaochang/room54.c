// Room: /u/mei/room54.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
ɽ�������･�����ߣ���Χ�ľ�����Ũ�����������֡�Ũ���е�ˮ��������
͸��������ѣ����������������ܡ��⡭�������˼�ͨ�����õ�·������ͨ��
����֮�ţ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"room55",
  "eastdown" : __DIR__"room53",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room54");

	setup();
	replace_program(ROOM);
}
