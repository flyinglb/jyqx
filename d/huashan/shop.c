//Room: /d/huashan/shop.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
�����ǻ�ɽɽ����һ��С�꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο�
��Ǯ��
LONG );
	set("exits", ([
		"east" : __DIR__"square",
	]));
//	set("no_clean_up", 0);
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

