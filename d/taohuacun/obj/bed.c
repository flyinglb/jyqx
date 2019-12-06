// bed.c 
// standard bed for players.
// by mon. 3/7/97

#include <ansi.h>

inherit ITEM;

int do_bed();

void create()
{
     set_name("ľ��",({"bed"}));
     set("short","ľ��");
     set("long", @LONG
һ�Ŵ�ľ���� 
LONG
     );
     set("out","/d/taohuacun/taohua7");
     set("exits", ([
         "out": this_object()->query("out"),
     ]));
       set_max_encumbrance(3000000);
       set_weight(1000000);
     seteuid(getuid());
     set("sleep_room",1);
     set("if_bed",1);
     set("no_fight", 1);
//     set("no_magic", 1);
     set("no_get",1);
     setup();
}

void init()
{
     object me=this_player(), env=this_object();

     if(env==environment(me))
     {
         add_action("go_out", "out");
     }
}

int go_out()
{
     object me=this_player();
     object out=this_object()->query("out");
     message_vision("$N�ƿ�ɴ�ʣ��Ӵ������˳�ȥ��\n",me);
     me->move(out);
     tell_room(out,me->query("name")+
         "�ƿ�ɴ�ʣ��Ӵ������˳�����\n",({me}));
     return 1;
}
