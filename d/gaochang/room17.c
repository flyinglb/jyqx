// Room: /u/mei/room17.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "ʯ��С��");
	set("long", @LONG
�˴��������Į������ط���Ȼ��ͬ����ػ�ɳ�л��Ŵִ�ʯ�������ִ�
�����������ף�ɽ�����ƴ��ֿɼ���·����ʮ�ֵ�������С�
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "room17");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room15",
  "north" : __DIR__"room18",
]));

	setup();
	replace_program(ROOM);
}
