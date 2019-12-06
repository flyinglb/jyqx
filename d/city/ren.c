//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
        set("short","铃月小居");
        set("long",@LONG
这是给玩家们改武器名的地方,方法是:ren 中文名 英文名
只有一些常用物品。
LONG );
        set("exits",([ /* sizeof() == 1 */
		"down" : "/d/city/wumiao",
	]));
	set("objects", ([
            __DIR__"npc/winzip" : 1,
	]));
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}
