//room: /d/btshan/zhailou.c
inherit ROOM;

void init();
int cut(string);

void create()
{
  set("short","����");
  set("long","������һƬï�ܵ�����(wood)���Ա�����һ��ľ��(pai)��\n");
  set("exits",([
        "west" : __DIR__"shulin1",
//      "nothwest" :
//      "northeast" :
      "south" : __DIR__"shanlu1",
     ]));
  set("outdoors", "baituo");
  set("no_clean_up", 0);
  set_temp("times" , 1);
  set("item_desc", ([
      "pai" : "��������  ��������\n",
      "wood" :"һƬ�ɿ��������֡�\n",
      ]) );
  setup();
}

void init()
{
 add_action("do_cut","cut");
}

int do_cut(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="wood")
  return notify_fail("��Ҫ��ʲô��\n");
 if (present("chai dao",me))
  return notify_fail("û�в���ô����\n");
 if (query_temp("times")==0)
  return notify_fail("������������\n");
 if(me->query("qi")<20)
  return notify_fail("�����̫���������ܿ���\n");
 ob=new(__DIR__"obj/chai");
 ob->move(environment(me));
 me->add("qi",-20);
 add_temp("times",-1);
 message_vision("$N����һ�����۵ù�Ǻ��\n" , me);
 return 1;
}

