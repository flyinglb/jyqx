// Room: /u/mei/room36.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
#include <room.h>
void init();
int do_push(string arg);
int do_ketou(string);
int do_move(string);
void create()
{
    set("short", "大殿");
    set("long", @LONG
走到殿口，只见大殿中也到处都是骸骨，刀剑散满了一地，想来当日必曾有过
一场激战。殿中地下到处是大大小小的玉制武器，刀枪剑戟都有，只是形状奇特，
与中土习见的迥然不同。骸骨前面有一块十分光滑的石板(stone)。
LONG
    );
        set("objects", ([ 
        __DIR__"skeleton" : random(6)+1,
        __DIR__"skeleton1" : 1,
        __DIR__"yusword" : 2,
        __DIR__"yublade" : 2,
        __DIR__"yuaxe" : 2,
]));
    set("exits", ([ 
        "west" : __DIR__"room35",
        "north" : __DIR__"room37",
]));
        set("item_desc", ([
        "stone" : 
"一块中间凹了下去的石板，看来以前经常有人在这里磕头(ketou)。\n",
          ]));
    setup();
    set("move_zhujian",1);
}
void init()
{
        add_action("do_move", "move");
        add_action("do_ketou", "ketou");
        add_action("do_study", "study");

}
int do_move(string arg)
{
        object me,ob;
        me = this_player();
        if ( !arg || arg!="skeleton" )
        return notify_fail("你要移什么？\n");  
        if( query("move_zhujian") ) {
        ob=new(__DIR__"obj/zhujian");
             write("你小心翼翼地将骸骨移开，发现下面有一堆竹简。\n");
        ob->move(this_object());
        add("move_zhujian",-1);
             return 1;
       }else
       return 0;
}
int do_ketou(string arg)
{
        object me;
        string dir;
        me = this_player();
        if (!arg||arg=="") return 0; 
        if( arg=="stone" ) {
                message_vision("\n$N试著磕了磕头，似乎没什么反应。\n", 
this_player());
        }
        if( sscanf(arg, "stone %s", dir)==1 ) 
        {
                if( dir=="4" || dir=="four") {               
                
message_vision("\n$N在石板上咚咚咚咚磕了四下，$N眼前一黑。\n", this_player());
                me->move(__DIR__"room73");
                }   
                else return 
notify_fail("\n你胡乱地磕了石板几下，结果什么也没发生。\n");
        }               
        return 1;
}
int do_study(string arg)
{
        object me;
        int    jing_cost;
        me = this_player();

       if (!me->query_temp("竹简"))
               return notify_fail("你要读什么1？");
               if ( !arg || ( arg != "zhu jian" ) )
                    return notify_fail("你要读什么2？");

        if ( (int)me->query_skill("literate", 1) < 1){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if ( (int)me->query_int() < 55){
                write("你的悟性不够，先学点文化(literate)吧。\n");
                return 1;
        }
        jing_cost = me->query("max_jing")/5;
        if((int)me->query("jing") < jing_cost){
                write("你看了看地上的竹简，似乎悟出了一些东西。\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );
        me->delete_temp("stone_learned");

        message_vision("$N正专心研读地上的竹简。\n", me);
        
        write("你对着竹简琢磨了一回儿，似有所悟。\n");

        if ( (int)me->query_skill("axe", 1) < 450 && random(10)>3 ){
                        me->improve_skill("axe", me->query_int());
                        me->set_temp("stone_learned",1);
                }
        return 1;
}

