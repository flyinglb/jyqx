// Room: /u/mei/room28.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
��ط����Ǹ����ľ������������Ʒ��Ȼ�����˲�֪�������£�����
��Ȼ��á�������һ˫Ů�˵Ļ�Ь��ɫ��������Ϊ���ޣ���������ϸ������֪
���ּ��ʱ��Ϊ�ҳ������ɵ�����һ����
LONG
	);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room26",
]));

	setup();
	replace_program(ROOM);
}
