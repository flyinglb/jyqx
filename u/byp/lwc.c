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
                "west":__DIR__"workroom",
                "south":__FILE__,
                "down":"/d/city/guangchang" ]));
        set("valid_startroom", 1);
        set("objects", ([
                "/d/baituo/npc/tong-ren" : 5,
                "/d/npc/tong-ren" : 5,
                "/clone/food/jitui" : 5,
                "/clone/food/jiudai" : 2,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/gangdao" : 1,
                "/clone/weapon/changbian" : 1,
                "/clone/weapon/gangzhang" : 1,
                "/clone/weapon/qimeigun" : 1,
                "/clone/weapon/gangjia": 1,
                "/d/city/obj/tiefu": 1,
                "/d/xiangyang/npc/obj/mujian": 1,
                "/d/xiangyang/npc/obj/mudao": 1,
                "/d/xiangyang/npc/obj/mugun": 1,
        ]));
        setup();
        set("sleep_room", 1);
}
int valid_leave(object me, string dir)
{
        if( dir=="south" ) {
                me-> receive_damage ("qi",10) ;
                me-> receive_wound  ("qi",10) ;
                write(HIR"突然一阵箭雨向你袭来，你一不小心被射中了几下。\n"NOR);
        }
        return ::valid_leave(me, dir);
}
