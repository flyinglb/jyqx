// Room: /city/xiaobaozhai.c

inherit ROOM;

void create()
{
	set("short", "С��ի");
	set("long", @LONG
��Զ�󽫾��ҹٳ��Ӻ󣬴����߸����ţ���������͵͵�������
С��ի����Щ����������Ľ����鱦���չ�һЩ�Ŷ���������ʵ����
���ٺ�ơ�
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("objects", ([
		"/quest/weixiaobao" : 1,
                "/d/city/npc/lingyueru" : 1,
	]));
	set("exits", ([
		"down"   : __DIR__"dangpu",
	]));

	setup();
	replace_program(ROOM);
}

