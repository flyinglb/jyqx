// Room: /liangbaobao/yongdao1.c
// Java. Sep 21 1998

inherit ROOM;

void create()
{
	set("short", "内洞");
	set("long", @LONG
这个就是古墓后山的洞穴，洞穴里不知名的小花,缀生其中，
洞穴除了一张石几，两只石椅之外，空荡荡的一无所有。
LONG );
        set("outdoors", "liangbaobao");
	set("exits", ([
            "out"  : __DIR__"shibi",
            "south"  : __DIR__"jianzhong",
	]));
	set("objects", ([       
                "/u/liangbaobao/yangguo": 1,
                "/u/liangbaobao/shendiao": 1,
	]));
//      set("no_clean_up", 0)
        setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    if( wizardp(me) ) return 1;
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "古墓派")) && (dir == "south"))
      return notify_fail("非古墓派弟子，到此止步吧。\n");
    else  return 1;
}
