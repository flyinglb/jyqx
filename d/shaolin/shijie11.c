// Room: /d/shaolin/shijie11.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ֽ�����������ǰ������һ������ʯ�������ֱͨ��ǰ����
�ص�ϡϡ��������ż��ð�����ȴ�Եøߴ�ͦ�Σ��������֦��
����ո߸���չ�š�
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie10",
		"north" : __DIR__"guangchang1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "southdown" ) return 0;

	return ::valid_leave(me, dir);
}

