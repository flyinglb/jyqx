// Room: /d/gaochang/room61.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
�������ֺó������˰��ʱ����ʼ���꣬һ�����֣�ֻ����ǰ������ѩ��ʹ
�˸������Ķ��ǡ���ɫ���¹�ӳ����ɫ��ѩ�����˾�������Ҳ������֮�У���
����ǧ���ޣ�һ����С�쳣��
LONG
);
	set("no_new_clean_up", 0);
	set("outdoors", "room61");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhang" : 3,
]));
	set("exits", ([ /* sizeof() == 3 */
  "westdown" : __DIR__"room62",
//  "south" : __DIR__"room64",
  "east" : __DIR__"room60",
]));

	setup();
	replace_program(ROOM);
}
