// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder
inherit ROOM;
void init();
int throw(string);
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
ǰ���Ѿ�û·��,Զ���ǻ�ɽ��.
LONG );
set("exits", ([
//                 "north" : __DIR__"hroad4",        
          //        "east" [D: __DIR__"road8",
                 "south"  : __DIR__"hroad3",
        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
}
void init()
{
   add_action("do_reng","reng");
}
int do_reng(string arg)
{
  object me;
me = this_player();
if(!arg||arg!="teng")
{
write("��ʲô!\n");
return 1;
}
if(!present("chang teng",me))
{
write("�������ĳ���!\n");
return 1;
}
if(random(5)<2)
{
write("�����һ��,���������ɽ�ڷ���,
���ڻ�ɽ������,���ٱ�������.\n");
me->set_temp("kao_teng",1);
return 1;
}
write("���Բ�����ôԶ,����һ��!\n");
return 1;
}

