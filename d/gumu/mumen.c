// mumen.c Ĺ��
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "Ĺ��");
        set("long", @LONG
���߹��˲ݵأ���ǰͻȻ��һƬ�����أ�ͻأ��������һ����Ĺ��
Ĺ������ʯͷ�Ѿ��ವ�ˣ����ĳ�����������Ĺ��Ĺǰû��������Ҳ
û���κεı�ǣ���֪������ǰ����λ�����󳼵�ĹѨ��Ĺ�ſڱ�һ
�������Ĵ�ʯͷ(shi)��յ�˿����͸��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "north" : __DIR__"caodi",
                "west"  : __DIR__"huangshalin",
        ]));

        set("objects", ([
                __DIR__"npc/yufeng" : 1+random(3),
        ]));

        set("item_desc", ([
        "shi": "���ǿ��ʯ���²���������£��������š�"+YEL"����ʯ"NOR+"�������֡�\n"
        ]) );

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_move", "move");
}


int do_move(string arg)
{
        object me=this_player();

        if( !arg || arg != "shi" ) {
                return notify_fail("��Ҫ�ƶ�ʲô��\n");
        }

        if((int)me->query_str()>33) //��������33
                {
                message_vision("$Nվ��ʯǰ��˫�Ʒ����ƶ���ʯ��ֻ���þ�ʯ֨֨������\n",this_player());
                message_vision("���������ȥ���ֳ�һ���Ż�����\n", this_player());
                set("exits/south", __DIR__"qianting");
                remove_call_out("close");
                call_out("close", 5, this_object());
                }
        else
                message_vision("$N���������ƾ�ʯ����ʯ��˿������ֻ�ð��ˡ�\n", this_player());
        return 1;
}

void close(object room)
{
        message("vision","ֻ����ʯ��֨֨�ػص�ԭ�ء�\n", room);
        room->delete("exits/south");
}
