
inherit ROOM;

void create()
{
	set("short", "���ͷ�");
	set("long", @LONG
���������ͷ���һ���ƹ��������ƶ��ڽ�����ɪɪ������
LONG );
	set("exits", ([
		"east" : __DIR__"kedian2",
	]));
	set("objects", ([
		"/d/city2/npc/zhanggui":1,
		"/d/city2/npc/huoji":2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

