// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void init();
int che(string);
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
Сɽ���Ϲ�ľ����(teng),ż��С����,������ȥ.
��֪����С��,׺������.
LONG );
set("exits", ([
                //  "south" : __DIR__"aroad3",
                 // "north" : __DIR__"aroad4",        
                // "east" : __DIR__"aroad",
   "west"  : __DIR__"aroad3",
        ]));
set("objects", ([
                __DIR__"npc/little_bee" : 2,
                        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
}
void init()
{
add_action("do_che","che");
}
int do_che(string arg)
{
object ob,me=this_player();
if(!arg||!arg="teng")
{
write("��ʲô!\n");
return 1;
}
if (present("chang teng",me))
 {
 message_vision("�����ϲ���������\n",me);
return 1;
}

write("�㳶��һ����,��̳���.\n");
ob=new(__DIR__"obj/teng");
ob->move(me);
return 1;
}


