// Room: /u/mei/room14.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "大漠风沙");
        set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼
的风声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间
仿佛只剩下你一个人。你脚下缓缓而动的流沙给你如履薄冰的感觉。
LONG
        );
        set("no_new_clean_up", 0);
        set("exits", ([ /* sizeof() == 8 */
  "south" : __DIR__"room14",
  "southwest" : __DIR__"room14",
  "north" : __DIR__"room14",
  "northeast" : __DIR__"room14",
  "east" : __DIR__"room14",
  "southeast" : __DIR__"room9",
  "west" : __DIR__"room14",
  "northwest" : __DIR__"room14",
]));

        setup();
}
void init()
{
    if ( userp( this_player() ) )
    call_out("kill_user",1,this_player());
}
int kill_user(object me)
{
   object ob;
   if (!me || environment(me)!=this_object()) return 1;
    if (!present("tu ying",this_object())){
    ob=new( __DIR__"npc/tuying");
    ob->move(this_object());
    message("vision","一个黑影突然从天而降。\n",this_object());
    }
}
int valid_leave(object me, string dir)
{
        int current_water;
        current_water = (int)me->query("water");
        if (!current_water) return 1;
        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }
        if (current_water>20) {
            me->set("water",current_water-20);
        }

    return 1;
}
