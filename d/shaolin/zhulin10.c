// /zhulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set ("long",@long
����һƬ���ܵ�����(zhulin)�������˼�������Ω�����ߵ��
·�棬��ɮ��ľ������΢�紵����Ҷ�������������������˳���Ϊ
֮һ�ӣ����Ǿ��ѵ��������ڡ�
long);
         set("outdoors","shaolin");
        set("resource/south", 1);

         set("item_desc",([
             "zhulin" : "����һƬ���ܵ����֡�\n"
]));
         set("exits", ([
             "south" : __DIR__"zhulin6",
]));
         setup();
}

void init()
{
        add_action("do_jump", "zuan");
}

               int do_jump(string arg)
               {
                    object me;
               me = this_player();
 if (arg !="zhulin")
              return notify_fail("��Ҫ����ȥ��\n");
          
             if (me->query_dex()<20) 
                    write("����ͼ������������������ݣ�ֻ�����ա�\n");
            else {
                    write("������Ҥ��������֡�\n");
                    message("vision",
                             me->name() + "��������֡�\n",
                             environment(me), ({me}) );
              me->move(__DIR__"linnei");
                    message("vision",
                             me->name() + "���������˳�����\n",
                             environment(me), ({me}) );
                return 1;
           }
}

