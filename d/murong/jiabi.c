// /u/beyond/mr/jiabi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"�б�"NOR);
         set("long",@long
������ܺ����һ���бڣ�Ҫ�����ƿ���ܵĺ��档���п��ܳ�ȥ��
long);
         set("exits",([
             "north" : __DIR__"hssg",
]));
         setup();
}
void init()
{
         add_action("do_push", "push");

}


int do_push(string arg)
{
        object me;
me = this_player();

        if (arg !="shujia") 
return notify_fail("��Ҫ��ʲô��\n");
 if( arg=="shujia")
        {
            
             write("������һ����ܣ����������һ�ơ�\n");
                    message("vision",
me->name() + "����һ��ͻȻ�����ˡ�\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"shufang");
                    message("vision",
me->name() + "���˹�����\n",
                             environment(me), ({me}) );
                }
                return 1;
            }

