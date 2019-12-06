// storeroom.c

inherit ROOM;
void init();
int do_open(string);
void do_close(object room);

void create()
{
        set("short", "������");
        set("long", "����һ�������ң������ܲ�͸�硣ֻ�йر��ŵĴ���(door)��\n");
//      case(random(6))
//        { case 0 :
//          case 1:
//                set("objects" , ([
//                 "  " :        ,
//                   ]));
//                  break;
        set("item_desc" , ([
         "door" : "һ��ľ�ţ�Ҳ���ܴ򿪡�\n",
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
  return notify_fail("��Ҫ��ʲô��\n");
 if(!( room = find_object(__DIR__"yuanzi")) )
    room = load_object(__DIR__"yuanzi");
 if(!objectp(room))  return notify_fail("ERROR:not found 'yuanzi.c' \n");
 if(room->query_temp("lock")==1)
   return notify_fail("���Ѿ���������ס�ˡ�\n");
        room->set("exits/enter", __FILE__);
        set("exits/out", __DIR__"yuanzi");
        call_out("do_close", 3, room);
/*
 message_vision("$N�����ƿ��ţ����˳�ȥ�����ְ�������������\n",me);
 message("vision", "�������˳��������ְ��������ˡ�\n",room);
 me->move(room);
*/
 return 1;
}
void do_close(object room)
{
        tell_room(this_object(),"һ���紵������ž��һ�������ˡ�\n");
        tell_room(room,"һ���紵������ž��һ�������ˡ�\n");
        delete("exits/out");
        room->delete("exits/enter");
}
