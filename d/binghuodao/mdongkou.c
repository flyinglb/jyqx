// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�Զ���");
        set("long", @LONG
��ʪ�ֳ���һ��ʯ��,��ɢ����Ұ�޵��ȳ�.

LONG );
set("exits", ([
               "enter" : __DIR__"midong",
                "south"   : __DIR__"dongcross",
        ]));
set("objects", ([
                __DIR__"npc/wolf" : 1,
                        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
       object ob;
        if ( dir == "south")
{
    ob=find_living("wolf");
   if(!ob)
    {
        return ::valid_leave(me, dir);
   }
    else 
     { 
       if( environment(me)== environment(ob) )
          { ob->kill_ob(me);
          return notify_fail("ѩ�ǵ���·��!\n");}

       }
     }
        return ::valid_leave(me, dir);
     
}

