// /u/beyond/mr/tingyuju.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",BLU"�����"NOR);
         set("long",
"��"WHT"�����"NOR"�����滷ˮ, �Ӵ�������ȥ, �����̲������۵ס������а���\n"
"һ�Ŵ�Բ��, ����������߹�����, ÿһ����ʮ�־��¡� Բ�����ܷ�����\n"
"�����ӡ�ǽ�ߵ�С���Ϸ���һ�ѡ�"BLU"��"NOR"����\n"
);        
         set("item_desc",([
             "floor" : "�����Աߵĵ��治��ʮ��ƽ����\n",
             "qin" : "����һ�ѹ��٣���һ����ʹ���Ŀ�������\n",
]));
         set("objects",([
             __DIR__"npc/azhu" : 1,
]));
         set("exits",([
"southeast" : __DIR__"xiaojing2",
])); 
         set("no_clean_up", 0);
}       
   
void init()
{
add_action("do_tan", "play");
add_action("do_tan", "press");
        add_action("do_tan", "tan");
}

int do_tan(string arg)
{
        object me;
     me = this_player();
        if (arg !="qin") 
return notify_fail("��Ҫ��ʲô��\n");
        if( arg=="qin")
        {
            
             write("�㵯��һ���٣�ͻȻ����һ�գ�������ȥ��\n");
                    message("vision",
             me->name() + "����һ���٣�ͻȻ����һ�գ�������ȥ��\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"xiaozhou");
                    message("vision",
                  me->name() + "������ĸ����е�������,�䵽һ��С���ϡ�\n",
                             environment(me), ({me}) );
                }
                return 1;
            }

