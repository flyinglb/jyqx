// muwu1.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "木屋");
	set("long", @LONG
这里是一间不大的木头屋子，但是麻雀虽小，五藏俱全，屋子中只是疏
疏落落地摆着几件家具，所以也不显得怎么小。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao5",
                "south" : __DIR__"yaogu",
	]));
 	set("objects", ([
		__DIR__"npc/kanggl": 1,
	]));
//	set("no_clean_up", 0);
	setup();
}
//int valid_leave(object me, string dir)
//{
//         if( dir=="south" && !wizardp(me) )
//        return notify_fail("测试中!请原谅!\n");
//        return ::valid_leave(me, dir);
//}
