// Room: /u/mei/room36.c

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
        __DIR__"obj/skeleton" : random(6)+1,
        __DIR__"obj/skeleton1" : 1,
        __DIR__"obj/skeleton" : random(6)+1,
        __DIR__"obj/yusword" : 2,
        __DIR__"obj/yublade" : 2,
        __DIR__"obj/yuaxe" : 2,
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
