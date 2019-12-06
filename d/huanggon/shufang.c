// shufang.c ���鷿

#include <room.h>
inherit ROOM;

int do_press(string arg);


void create()
{
        set("short", "���鷿");
        set("long", @LONG
�����ù���������鷿.�������������ż������,��������Щ����
����,�㰵�Ե�,ԭ������Ҳ����ô���鰡.�鷿�������ž����̴��ľ
��(desk),���ϰ��ż������澫���Ĳ���.
LONG
        );
        set("exits", ([
                "south" : __DIR__"tinglang1",
]));
        set("item_desc", ([
        "desk" : "һ������������̴��ľ����.\n",
        ]));
        set("objects", ([
//                __DIR__"npc/kangxi" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_press", "press");
}

int do_press(string arg)
{
        if( !arg || arg=="") return 0;
        if( arg=="desk")
        {
                message_vision("������һ������,ͻȻǽ������п�һ������.\n", this_player());
                set("exits/enter", __DIR__"mishi");
        remove_call_out("close");
                call_out("close", 1, this_object());
                return 1;
        }
}

void close(object room)
{
        message_vision("֨ѽһ��,�����ֺ�����.\n", room);
        room->delete("exits/enter");
}
