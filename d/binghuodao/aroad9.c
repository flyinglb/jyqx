// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void init();
int kan(string);
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��ȥɽ���淢��,��ľ(wood)����.
ȥ·,����.
LONG );
set("exits", ([
                  "southdown" : __DIR__"aroad4",
                 // "north" : __DIR__"aroad4",        
                // "east" : __DIR__"aroad",
                // "west"  : __DIR__"road6",
        ]));
set("objects", ([
                __DIR__"npc/deer" : 2,
                        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
 set("item_desc", ([
      "pai" : "��������  ��������\n",
      "wood" :"һƬ�ɿ��������֡�\n",
      ]) );
        setup();
//        replace_program(ROOM);
}
void init()
{
 add_action("do_kan","kan");
}

int do_kan(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="wood")
 {
tell_object(me,"��Ҫ��ʲô��\n");
return 1;}


 if (!present("cai dao",me))
 {
 message_vision("û�е���ô����\n",me);
return 1;
}

if (present("mu chai",me))
 {
 message_vision("�����ϲ���������\n",me);
return 1;
}

// if (query_temp("times")==0)
// {
// message_vision("������������\n",me);
//return 1;}
 if(me->query("qi")<20)
  {
message_vision("�����̫���������ܿ���\n",me);
return 1;}

 ob=new(__DIR__"obj/chai");
 ob->move(me);
 me->add("qi",-20);
 add_temp("times",-1);
 message_vision("$N����һ�����۵ù�Ǻ��\n" , me);
 return 1;
}

