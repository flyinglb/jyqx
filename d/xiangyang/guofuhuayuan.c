// Room: /d/xiangyang/guofuhuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
�����ǹ����ĺ�԰��԰�ڼ�ɽ��������������һЩ����
�����Ǽ���֦Ҷïʢ��ľ�ʻ�������һ�߽��������ŵ�һ����
���µġ������Ļ��㡣
LONG );
	set("exits", ([
		"east"  : __DIR__"guofuwoshi",
		"west"  : __DIR__"guofukefang",
		"south" : __DIR__"guofuting",
		"north" : __DIR__"guofushufang",
	]));
	set("objects", ([
		__DIR__"npc/huang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

