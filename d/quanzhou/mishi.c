// room: mishi.c
//Jay 4/7/96

#include <room.h>

inherit ROOM;
int do_press();

void create()
{ 
       set("short","����");
       set("long", @LONG
����һ��������С���䣬ǽ�ϵ�שͷ(zhuan)�Ѿ��������ˣ�����
(liang)Ҳ�Ѿ����ò�����ǽ�Ŵ���һ�������ӣ���������˳�����
LONG );
        set("exits", ([
                "out" : __DIR__"midao",
        ]));       
        set("item_desc", ([
                "zhuan" :      
        "שͷ�õ�һ����Ϳ��\n",
                "liang" :
        "�������Ϻõ��ľ���ģ���ϧ���̫�ã��Ѿ����õò��������ˡ�\n",
        ]) );
        set("objects", ([
                __DIR__"obj/tiexiang" : 1,
        ]));       
//        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) 
                return 0;
        if( arg=="liang")
        {
            if (me->query_temp("marks/��1") ) {
                if (me->query_dex()<20) 
                    write("����ͼ���Ϸ������������������ݣ�ֻ�����ա�\n");
                else {
                    write("������Ծ���˷�����\n");
                    message("vision",
                             me->name() + "һ����Ծ���˷�����\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"liang");
                    message("vision",
                             me->name() + "������Ծ��������\n",
                             environment(me), ({me}) );
                }
                return 1;
           }
        }
}

int valid_leave(object me, string dir)
{
        me->delete_temp("marks/��1");
        return ::valid_leave(me, dir);
}
 
