// Room: /huanghe/shidong.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void init();
int do_insert(string);
void create()
{
	set("short", "石洞");
	set("long", @LONG
这是沙漠中天然形成的一个石洞，洞中光线昏暗，但却十分干燥，
地下铺者几堆稻草，似乎是供人睡卧之用，静心凝听，洞中仿佛有阵阵
水声。洞的一角放着数堆人头骨(skulls)。
LONG );
	set("exits", ([
		"out" : __DIR__"shamo1",
	]));
	set("item_desc", ([
		"skulls" : "一堆整整齐齐的骷髅头，上一中三下五，不多不少，恰是
九颗白骨骷髅头。\n",
	]));
	set("objects", ([
		__DIR__"npc/mei" :1,
		__DIR__"npc/chen" :1,
	]));
//	set("no_clean_up", 0);
	setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_insert","insert");
}

int do_insert(string arg)
{
        object ob;
        int c_skill;
        int exp;

        if (arg != "skulls") return 0;
        ob = this_player();
        exp = ob->query("combat_exp");
        c_skill=(int)ob->query_skill("claw", 1);

        if (ob->query("qi")<120)
                return notify_fail("你太累了，无法再把手指插进骷髅头了。\n");
        if (c_skill< 200)
                return notify_fail("你爪法修为还不够，无法把手指插进骷髅去。\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("qi", 50);
                return notify_fail("你的经验不够，五指插进骷髅也没什么用。\n");
        }

        message_vision("$N把手凝成爪状，不断将五指疯狂地插进骷髅。\n",ob);
        ob->improve_skill("claw", random(100*ob->query_int()));
        ob->receive_damage("qi", 100);
        return 1;
}


