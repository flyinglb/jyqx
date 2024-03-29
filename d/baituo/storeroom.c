// storeroom.c

inherit ROOM;
void init();
int do_open(string);
void do_close(object room);

void create()
{
        set("short", "储藏室");
        set("long", "这是一个储藏室，四周密不透风。只有关闭着的大门(door)。\n");
//      case(random(6))
//        { case 0 :
//          case 1:
//                set("objects" , ([
//                 "  " :        ,
//                   ]));
//                  break;
        set("item_desc" , ([
         "door" : "一扇木门，也许能打开。\n",
         ]) );
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
 add_action("do_open","open");
}

int do_open(string arg)
{
//  object me=this_player();
  object room;
 if( !arg|| arg!="door")
  return notify_fail("你要开什么？\n");
 if(!( room = find_object(__DIR__"yuanzi")) )
    room = load_object(__DIR__"yuanzi");
 if(!objectp(room))  return notify_fail("ERROR:not found 'yuanzi.c' \n");
 if(room->query_temp("lock")==1)
   return notify_fail("门已经从外面锁住了。\n");
        room->set("exits/enter", __FILE__);
        set("exits/out", __DIR__"yuanzi");
        call_out("do_close", 3, room);
/*
 message_vision("$N轻轻推开门，走了出去，随手把门掩了起来。\n",me);
 message("vision", "有人走了出来，随手把门掩上了。\n",room);
 me->move(room);
*/
 return 1;
}
void do_close(object room)
{
        tell_room(this_object(),"一阵大风吹过，门啪的一声关上了。\n");
        tell_room(room,"一阵大风吹过，门啪的一声关上了。\n");
        delete("exits/out");
        room->delete("exits/enter");
}
