// Room: /d/gaochang/room47.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ֻ�����ߺ컨���£�����һ��ȫ����µ���Ů���������磬������һ��������
������������˫�ţ����Ϸ��϶���ˮ�顣ֻ�����������ڵ����ں��ߣ�����ʥ�࣬
��̬���ɷ�����µ�ӳˮ�У��仨һ��һ��ĵ�����ͷ�ϡ����ϡ�Ӱ���ϡ��ζ�
ƽʱ����������磬��ʱ�����ŵ�˵����������
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room48",
  "east" : __DIR__"room46",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huoqingtong" : 1,
]));
	set("outdoors", "room47");
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
