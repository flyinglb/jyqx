// /zhulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short"," �ڶ�ָ��");
         set ("long",@long
�����ѵ�����ָ��İ�ɽ���ˣ���������ɽ���е�����ָһ���� 
ÿ��ɽ���ַ����أ�������ָ��ָ��һ�㣬�����������λ�ڵڶ�
ָ�ڵ�λ�á�������嶥�ѽ���͸���������������ѿ��Կ���ɽ
·�ľ�ͷ�ˡ���ǰ����ʮ���ɴ��������������һ����Ѩ��������
����ʯ���޽��ü���������
long);
         set("outdoors","shaolin");
        set("resource/south", 1);

         set("item_desc",([
             "dong" : "һ���������ɽ�����ڰ���ż���м����׹������������ˡ�\n"
]));
         set("exits", ([
  "south" : __DIR__"sslin-5",
  "northup" : __DIR__"shanlu-8",

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
 if (arg !="dong")
              return notify_fail("��Ҫ����ȥ��\n");
          
             if (me->query_dex()<20) 
                    write("����ͼ������������������ݣ�ֻ�����ա�\n");
            else {
                    write("������������˶��\n");
                    message("vision",
                             me->name() + "����˶��\n",
                             environment(me), ({me}) );
              me->move(__DIR__"dong-1");
                    message("vision",
                             me->name() + "�Ӷ������˳�����\n",
                             environment(me), ({me}) );
                return 1;
           }
}


