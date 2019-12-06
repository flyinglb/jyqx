// hanshuitan.c ��ˮ̶
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_qian(string arg);

void create()
{
        set("short", "��ˮ̶");
        set("long", @LONG
�����ǲݵصı�Ե������Ѿ���ϡ���ˣ���Ȼ��һ��������ص�
�ɹ�Ѱ��ʳ������ǰ��һ���岨�����Ĵ�ˮ̶ (tan)��ˮ���壬
��Լ���Լ���ˮ�׵Ĺ�ʯ��ᾣ�һ������ٿ�ش�ˮ���ι����ֲ�֪��
�㵽�Ŀ�ʯͷ�������ȥ�ˡ�����ӳ���£�ˮ�淺����һ����ɫ�ʺ磬
����������������������
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northwest" : __DIR__"caodi2",
        ]));

        set("objects", ([
                __DIR__"npc/yufeng" : random(3),
        ]));

        set("item_desc", ([
        "tan": "һ�ں����ˮ̯����֪���ɲ�����Ǳ(qian)�µ���ˮ������ȥ��\n"
        ]) );

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_qian", "qian");
}


int do_qian(string arg)
{
        object me=this_player();

        if( !arg || arg != "tan" ) {
                return notify_fail("��Ҫ������Ǳˮ��\n");
        }

        message_vision(HIG"$N����һԾ������ˮ̯֮�У���������������ι���
������һ�̣�\n"NOR,this_player());
        message_vision(HIG"ȴץ�˿ա�ͻȻ$N��ǰһ����һ�ɰ��������������$N
����һ�����ڡ�\n"NOR, this_player());

        me->move(__DIR__"mishi1");

        return 1;
}

