//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
        set("short","宗师的工作室");
        set("long",@LONG
这里就是宗师的家了。红木制作的家私使得整个屋子显得古色。
LONG);
        set("exits",([ /* sizeof() == 1 */
                "down" : "/d/city/chaguan3",
                "north":"/d/wizard/wizard_room" ]));
        set("objects", ([
                __DIR__"biaotou" : 1,
        ]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}
