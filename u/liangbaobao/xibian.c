// Room: /liangbaobao/xibian.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "溪边");
        set("long", @LONG
一个山峡，水声震耳欲聋，只见山峰间一条大白龙似的瀑布奔泻而下，冲
入一条溪流，奔胜雷鸣，湍急异常，水中挟着树枝石块，转眼便流得不知去向。 
四顾水气蒙蒙，蔚为奇观。
LONG );
        set("outdoors", "city");
        set("valid_xuantie-sword",1);
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"jianzhong",
        ]));

        setup();
        replace_program(ROOM);
}
