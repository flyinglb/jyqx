// Room: /u/mei/caoyuan4.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
�˴��������Į������ط���Ȼ��ͬ����ػ�ɳ�л��Ŵִ�ʯ�������ִ�
�����������ף�·ʮ�ֵ�������С�
LONG
	);
	set("outdoors", "caoyuan4");
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan5",
  "east" : __DIR__"caoyuan3",
]));

	setup();
	replace_program(ROOM);
}
