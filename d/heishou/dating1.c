inherit ROOM;
#include <mudlib.h>
void create()
{
        set("short", "大厅");
        set("long", @LONG
这是五指山庄的正厅，虽然屋子中装修没有什么，但打扫得十分干
净，光线也较为充足。四壁挂着一些古人书画精品，皆为上乘之作，显
得主人眼光不凡，胸中大有丘壑。
LONG );
        set("valid_startroom",1);
        set("no_steal", "1");
        set("no_sleep_room", "1");
        set("no_fight","1");
        set("item_desc",([
//                "duilian" : "海外仙岛曾飘血，洞天福地舞神龙\n",
        ]));
        set("exits", ([
                "south"  : __DIR__"qianyuan",
                "north"  : __DIR__"huiyi",
                "west"  : __DIR__"eatroom3",
                "east"  : __DIR__"ligong",
        ]));
        setup();
        "/clone/board/heishou_b"->foo();

        }

