// liangong.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���������е�һ��ʯ�ݣ������Ե�ʲô�徻�ͼ��ӣ������в�û��ʲô
�ر�İ�������������ܵ��κζ�����ɧ�ţ��Ǹ������ڹ��ĺõط���
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
