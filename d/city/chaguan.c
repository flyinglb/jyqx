// Room: /d/city/chaguan.c
// Created by Eatdami@MX

inherit ROOM;

string *discard_cmds =({"sleep","respitate","jingzuo","array","duanlian","ansuan",
                        "touxi","persuade","teach","exert","exercise","study",
                        "learn","kill","steal","conjure","fight","hit","perform",
                        "practice","research","lian","tuna","yun","du","dazuo"});
void create()
{
	set("short", HIM"春来茶馆"NOR);
	set("long", @LONG
这便是江湖闻名的春来茶馆。这里的居民没事的时候常在这儿聊天
，打听江湖掌故和谣言。你一走进来，就闻到一股茶香沁入心脾，精神
为之一爽。几张八仙桌一字排开，坐满了客人，或高声谈笑，或交头接
耳，四周是几个茶室。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"east"  : __DIR__"nandajie2",
		"west"  : __DIR__"chaguan1",
		"south" : __DIR__"chaguan2",
		"north" : __DIR__"chaguan3",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
		__DIR__"npc/baixiaosheng" : 1,
	]));

	set("valid_startroom","1");
        set("no_fight","1");

	setup();
        "/clone/board/player_b"->foo();
}

void init()
{
    if (wizardp(this_player()))
        return;
    add_action("discard",discard_cmds);
}

int discard()
{
        tell_object(this_player(),"别在这里瞎折腾了。\n");
        return 1;
}

int valid_leave(object me, string dir)
{
//        if( (dir=="south" || dir=="north" || dir=="west") && !wizardp(me) ) {
//                tell_object(me,HIR"此处现在暂时被封闭了，你过不去！\n"NOR)
        if( (dir=="south" || dir=="north" || dir=="west") && !userp(me) )
                return 0;
//        }
        return ::valid_leave(me, dir);
}

