//Room of wizard that haven't modify own workroom.


//inherit CHATTING_ROOM;
inherit ROOM;

void create()
{
        set("short","练武场");
        set("long",@LONG
这是没有建造工作室的巫师的临时住处，这里的设备非常简单，
只有一些常用物品。
LONG );
        set("exits",([ /* sizeof() == 1 */
                "north":"/d/wizard/wizard_room",
                "down":"/d/city/guangchang" ]));
        set("valid_startroom", 1);
        set("objects", ([
                __DIR__"npc" : 1,
//                "/d/npc/tong-ren" : 5,
        ]));
        set("no_clean_up", 1);
        setup();
//        set("sleep_room", 1);
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

void init()
{
        object me;
        
        me = this_player();
        if(me->query("id")=="byp") {
                me->set("startroom",base_name(environment(me)));
        }
}

