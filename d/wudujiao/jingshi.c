// by mayue


inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���谵�ķ��䣬���˼��Ŵ�֮��ʲô��û�С����ڹ��߻谵����
���ɵĴ���һ����Ƿ��
LONG
	);
//      set("outdoors", "wudujiao");
        set("sleep_room", 1);
        set("no_fight", 1);
//      set("valid_startroom", 1);

	set("exits", ([
//		"east" : __DIR__"huayuan1",
//		"south" : __DIR__"jingshi",
//		"west" : __DIR__"lianwu",
		"north" : __DIR__"dating",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

