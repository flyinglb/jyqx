// by mayue


inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǳ�Ժ��Ժ���ﾲ���ĵġ�������һ��������ԶԶƮ��һ
�ɷ��㣬���Ǹÿ����ˡ�  
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"bingqi",
		"south" : __DIR__"lianwu",
//		"west" : __DIR__"damen",
		"north" : __DIR__"chufang",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}

