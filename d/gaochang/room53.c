// Room: /u/mei/room53.c// This is a room made by roommaker. write by Fan. :)
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
  "westup" : __DIR__"room54",
  "southdown" : __DIR__"room50",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room53");

	setup();
	replace_program(ROOM);
}
