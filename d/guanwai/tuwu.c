// /guanwai/tuwu.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ���û����ݳɵ�С�ݣ����ڴ�ɨ�ĺܸɾ������ܵ�ǽ���Ϲ�����
���ֹ��ӣ�ǥ�ӣ���ɽ����С���ӵȹ��ߣ������ƺ��ǲɲ����õĹ��ߡ���
������Ļ�������һλ������͵����ˣ��������ź��̴���
LONG );
	set("exits", ([
		"north" : __DIR__"xiaoxiang",
	]));
	set("objects", ([
		__DIR__"npc/heersu" : 1,
	]));
//	set("no_clean_up", 0);
//	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

