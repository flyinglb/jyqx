// muwu1.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
这里就是白驼山大厅东边的偏房。一个不大的石屋，靠墙的柜子上
放着大大小小几是个罐子，一个面目可怖的老人一言不发的注视着你！
LONG );
	set("exits", ([
                "west" : __DIR__"dating",
                "east" : __DIR__"sheku",
	]));
 	set("objects", ([
        __DIR__"npc/laogu" : 1,
	]));
        set("no_fight", "1");
        replace_program(ROOM);
	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="east" && me->query("family/family_name") != "白驼山派" )
        return notify_fail("那里只有白驼山弟子才可以进出！\n");
        return ::valid_leave(me, dir);
}
