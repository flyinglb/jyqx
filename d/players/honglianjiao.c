// Room: /d/players/honglianjiao.c

inherit ROOM;

void create()
{
        set("short", "红莲教会");
	set("long", @LONG
这里便是红莲教处理教务的地方,厅里横匾上明显看到【红莲教】三个大
红字厅中央的大圆桌上堆满了历代门人的资料,和一写教众的汇报记录，这里
由于建教年代以久，看起来已颇为陈旧.但打扫的十分干净四壁挂着一些古人
书画精品，皆为上乘之作。其中一张书画上提着红莲教的宗旨(paper)
LONG );
	set("exits", ([
                "north" : "/d/foshan/road10",
	]));
         set("objects",([
                 __DIR__"npc/honglianjiao" : 2,
        ]));
        set("item_desc", ([
 "paper" : "    红莲教的成立唯一的目的是团结大家在 MUD 的世界里更好的游戏人间。\n"
"在这个充满 PKER 的世界里，练功的时候总是提心掉胆，实在不怎么样凡是\n"
"加入红莲教的玩家教里的个人将尽力帮助，使其跟安全的踏上大狭之路以便\n"
"以后能维持金庸的正义！\n",
        ]));
        set("valid_startroom", 1);
        set("no_fight", "1");
          setup();
//          "/clone/board/honglianjiao"->foo();
	replace_program(ROOM);
}

