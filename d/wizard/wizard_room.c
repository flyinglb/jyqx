// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
        set("short", "巫师休息室");
        set("long", @LONG
这里就是「新金庸群侠传」巫师的休息所在，刚粉刷过的四周墙
壁上光秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着
一本巫师留言簿(board)。
LONG );

        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guest_room",
                "north" : __DIR__"academy",
        ]));
//set("no_fight", "1");
        set("no_clean_up", 0);
        setup();

        call_other("/clone/board/wiz_b", "???");
        replace_program(ROOM);
}

