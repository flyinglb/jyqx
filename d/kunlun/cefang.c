//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void do_close_hole();
void do_wugu_therapy_down(object me);

void create()
{
        set("short","侧房");
        set("long", @LONG
这里是何太冲第五位夫人五姑的卧室，房中充满了药味，而五姑却躺在床
上，看来卧病时间已经不少了。床(bed)下有些新鲜的泥土，与这药气扑鼻而
又整洁异常的环境不甚相符。房内的窗口(window)似乎面对着后花园的某一
种花草。
LONG );
        set("exits", ([
                "east" :  __DIR__"houhuayuan",
        ]));
        set("item_desc", ([

                "bed" : "一张木制牙床，虽然上面躺着一个人，但似乎还是能移动的。\n",
                "window" : "看看是不是可以跳出去……\n",
        ]));
        set("objects", ([
                __DIR__"npc/binv" : 2,
        ]));
        set("snake_count",6-random(10));
        setup();
}
void init()
{
        add_action("do_move", "move");
        add_action("do_dig", "dig");
        add_action("do_use", "use");
        add_action("do_jump", "jump");
}
int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg != "bed") return 0;
        if( present("wu gu", this_object()) ) {
                message_vision("五姑对$N惊叫到：“你在这乱翻腾个什么劲？”\n",me);
                return 1;
        }
        
        if( query("temp/snake_hole") ) {
                write("这床已经被挪开了。\n");
                return 1;
        }
        message_vision("$N用力抬起床，移向一边，看到了墙角的一个小洞(hole)。\n",me);
        add("item_desc", ([
                "hole" : "看不清底的小洞，是不是可以挖(dig)出什么来。\n",
        ]));
        remove_call_out("do_close_hole");
        if( query("temp/snake_hole") < 1 )
        set("temp/snake_hole", 1);
        call_out("do_close_hole",10);
        return 1;
}

int do_dig(string arg)
{
        object me, ob1, ob2;
        me = this_player();
        if (!arg || arg != "hole") return 0;
        if( !query("temp/snake_hole") ) return notify_fail("你要挖什么？\n");
        if( !present("lingzhilan", me) ) {
                message_vision("洞里窜出一条蛇，在$N的手指上咬了一口，旋即缩了回去。\n",me);
                me->die();
        }
        else if (query("snake_count") < 1) {
                message_vision("$N挖了半天，洞里什么也没有。\n",me);
        } else {
                set("snake_count", 0);
                message("vision","洞里一前一后游出两条蛇，嗅着灵脂兰的气息，爬了出来。\n",this_object());
                ob1 = new(__DIR__"obj/jinshe");
                ob2 = new(__DIR__"obj/yinshe");
                ob1->move(me);
                ob2->move(me);
        }
        return 1;
}

int do_use(string arg)
{
        object me, ob;
        me = this_player();
        if(!arg || (arg !="jinshe" && arg != "yinshe") ) {
                write("你要驱使什么？\n");
                return 1;
        }
        if( present("wu gu", this_object()) ) 
                message ("vision", "五姑好好的，你想害人呀。\n", me);
        else if(!ob = present(arg, me)) {
                        if(ob = present(arg,environment(me)) ) {
                                write("这里没有这样东西\n");
                                return 1;
                        }

        } else if (arg == "jinshe") {
                message_vision (HIY "金色血蛇"NOR"从$N的衣带中爬出，钻进了床上的被子里。\n",me);
                ob->move(VOID_OB);
                destruct(ob);
                set("temp/jinshe", 1);
        } else {
                message_vision (HIW "银色血蛇"NOR"从$N的衣带中爬出，钻进了床上的被子里。\n",me);
                ob->move(VOID_OB);
                destruct(ob);
                set("temp/yinshe", 1);
        }
        if( query("temp/jinshe") && query("temp/yinshe") ) {
                message("vision","两条血蛇钻进被子里后，但见床上昏迷的五姑突然一动……\n",this_object());
                set("temp/jinshe", 0);
                set("temp/yinshe", 0);
                set("in_wugu_therapy",1);
                call_out("do_wugu_therapy_down",20, me);
        }
        return 1;
}
int do_jump(string arg)
{
        object me;
        if (!arg || arg != "window") return 0;
        me = this_player();
        message_vision("$N从窗户跳了出去。\n", me);
        me->move(__DIR__"houhuayuan1");
        message_vision("$N从五姑房的窗子跳了过来。\n", me);
        return 1;
}

void do_close_hole()
{
        if( query("in_wugu_therapy") ) return;
        message("vision","婢女哼了一声，你别在这里打扰五夫人了，说着把床推了回去。\n",this_object());
        set("temp/snake_hole", 0);
}

void do_wugu_therapy_down(object me)
{
        object npc;
        message("vision","过了一会，五姑呻吟着下了床。那两条血蛇却不知哪里去了……\n",this_object());
        npc = new(__DIR__"npc/wugu");
        npc->move(this_object());
        set("in_wugu_therapy",0);
        set("temp/snake_hole", 0);
        me->set_temp("kunlun/help_wugu",1);
}
