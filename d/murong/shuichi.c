// /u/beyond/mr/shuichi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",BLU"ˮ��"NOR);
         set ("long",@long
����һ��ˮ�ء�һ��΢�紵����ˮ�к�Ҷ�����ˮ����Ư��, ˮ��(mian)
�̲�ӿ������ԡ�ˮ��������һ����ɽ�����е�ʯ���Ǻܶ�ģ�ʹ���̲�
ס��̽��������
long);
         set("outdoors","mr");
	set("resource/water", 1);

         set("item_desc",([
             "mian" : "ˮ�淺����������˸�ŵ���������ֻ�������ںɻ��ϡ�\n"
]));
         set("exits", ([
             "west" : __DIR__"xiaojing7",
]));
         setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_strike","strike");
        add_action("do_strike","hit");
        add_action("do_clean","diu");
}

               int do_jump(string arg)
               {
                    object me;
               me = this_player();
 if (arg !="shuichi")
              return notify_fail("��Ҫ����ȥ��\n");
          
             if (me->query_dex()<17) 
                    write("����ͼ����ˮ�أ��������������ݣ�ֻ�����ա�\n");
            else {
                    write("������������ˮ��,�䵽�˼�ɽ�ϡ�\n");
                    message("vision",
                             me->name() + "һ����Խ����ˮ�ء�\n",
                             environment(me), ({me}) );
              me->move(__DIR__"jiashan");
                    message("vision",
                             me->name() + "��ˮ�ر�Ծ��������\n",
                             environment(me), ({me}) );
                return 1;
           }
}

int do_clean(string arg)
{
    object me = this_player();
    object ob;                             
    if (! (ob = present("paper", me)) || userp(ob))
    return notify_fail("��Ҫ��ʲô��\n");
    if (arg != "paper" && arg != "ֽ��") 
    return notify_fail("��Ҫ��ʲô��\n");
    write("�㲻����İ�ֽ����ˮ���С�\n",me);
    write("ֽ�����ɾ��ˣ��Գ���һ����С�֡�\n", me);
    destruct(ob);
ob = new("/d/murong/obj/paper1.c");
    ob->move(me);
    return 1;
}

