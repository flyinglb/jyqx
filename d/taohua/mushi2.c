// /zhulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","Ĺ��");
         set ("long",@long
����һ��Ĺ�ҡ�Ĺ������һ���ر��������������⡣��Χ��
�ѷ����������������档Ĺ��ǽ���Ϲ���һ��������Ȼһ�����紵
�����㲻������һ��������
long);
         set("outdoors","shaolin");
        set("resource/south", 1);

         set("item_desc",([
             "hua" : "һ�������ٸ��Ļ���\n"
]));
         set("exits", ([
             "south" : __DIR__"mushi",
]));
         setup();
}

void init()
{
        add_action("do_jump", "xian");
}

               int do_jump(string arg)
               {
                    object me;
               me = this_player();
 if (arg !="hua")
              return notify_fail("��Ҫ����ȥ��\n");

             if (me->query_dex()<20)
                    write("����ͼ������������������ݣ�ֻ�����ա�\n");
            else {
                    write("������Ҥ����˻��ڡ�\n");
                    message("vision",
                             me->name() + "����˻���\n",
                             environment(me), ({me}) );
              me->move(__DIR__"mishi");
                    message("vision",
                             me->name() + "�ӻ����˳�����\n",
                             environment(me), ({me}) );
                return 1;
           }
}
