//Room: /d/dali/wangfugate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","王府大门");
	set("long",@LONG
你正站在一座豪华的府门前，门前有两只极大的石狮子，门上高
悬一块横匾，上书「镇南王府」四个金字。门口站着两排侍卫，身着
锦衣，手执钢刀，气宇轩昂。
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/zhuwanli": 1,
	   __DIR__"npc/weishi2": 1,
	   __DIR__"npc/weishi1": 2,
	]));
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : __DIR__"wfdating",
	    "south"  : __DIR__"wangfulu",
	]));
	setup();
	"/clone/board/dali_b"->foo();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

	if( objectp(present("zhu wangli", environment(me))))
       	 if ((!myfam || myfam["family_name"] != "大理段家") && dir == "enter")
           return notify_fail("褚万里拦住你说：闲杂人等，别到处乱窜。\n");

        return ::valid_leave(me, dir);
}
