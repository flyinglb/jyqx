// shanbi.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山壁");
        set("long", @LONG
这里是终南山绝壁上的山壁。山壁似乎有个山洞(dong)。你向下一
望，只见脚下雾气一团团的随风飘过，绝峰险岭，却不看见地。转头
向洞里张望，黑沉沉的看不清楚，只觉得洞穴很深。洞口甚小，那是
钻不进去。
LONG );
        set("outdoors", "jinshe");
        /*
        set("exits", ([ 
		"up" : __DIR__"zhufeng",
        ]));
        */
        set("item_desc", ([
            "dong" : "一个被石快(stone)堵住的山洞。\n"
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_break", "break");
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();
        
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="up") )
                return 0;
        
        tell_room(environment(me),me->name()+"一转身，向着崖壁爬上去　……\n",({me}));
        tell_object(me,"你顺着山藤慢慢的向着山顶爬去　……\n\n");
        me->move(__DIR__"zhufeng");
        tell_room(environment(me),me->name()+"不知从那晃了出来 ……\n",({me}));
        return 1;
}

int do_break(string arg)
{
        object me=this_player();
        if (arg != "stone") return 0;
        message_vision(HIY
"$N走到洞口前，运气双掌，猛地击向巨石！\n"NOR,me);

        if (me->query("neili") < 100)
        {
               message_vision(HIY
"结果只听一声闷哼，$N被巨石的反弹力震得眼前一黑....\n"NOR,me);
               me->set("neili",0);
               me->unconcious();
               return 1;
        }

        if(me->query_temp("tmark/杨") < 2) {
               message_vision(HIY"结果只听一声闷响，$N被巨石的反弹力震得双手发麻....\n"NOR,me);
                return 1;
        }

        message_vision(HIY
"$N只听一声轰响，巨石被捅穿了，原来里面有一个大洞！\n"NOR,me);
        set("exits/enter",__DIR__"yongdao1");
        me->add("neili",-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        return 1;
}

void close(object room)
{
    message("vision","崖上忽然掉下来一块大土块，将洞口封了个严严实实。\n", room);
    room->delete("exits/enter");
}

int valid_leave(object me, string dir)
{
        if( dir=="enter" && ::valid_leave(me,dir) )
                 me->delete_temp("tmark/杨");
        return ::valid_leave(me, dir);
}
