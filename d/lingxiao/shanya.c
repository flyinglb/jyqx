// Room: shanya.c
#include <ansi.h>
inherit ROOM;
int do_open(string arg);

void create()
{
        set("short","ɽ��");
        set("long",
"ӳ�����������֮��ģ���һ��Ρ��֮���Ĵ�ǡ�ֻ����ǽ
�������ɣ�ǽͷǽԫѩ��һƬ�����Ǳ�ѩ����ǽ����������ͷ��
������ͷ����һ���������չ�Ĵ��죬����д���������֣�"HIW"
                      ������"NOR"
����ǰ��һ�ź��ĵ��ţ�bridge�����������ر��š������Ҫ
����Ļ�������Ҫ���˿���open�����С�\n");
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"cityout",
            "west"  : __DIR__"cityout1",
            "down"  : __DIR__"bingti",
        ]));
        if(random(6)>3)
        set("objects", ([
                "/quest/wakuang/kuang/kuangmai" : 1,
        ])); 

        set("item_desc", ([
        "diaoqiao": "һ�ż���ĵ���,���������سǵ�һ�����ߡ�\n"
        ]) );
        setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me=this_player();

        if( !arg || arg != "bridge" ) {
                return notify_fail("���ҽ�ʲô��\n");
        }

       message_vision("$N��������,���һ��:'����ѽ'��\n",this_player());
       message_vision("ֻ���ó�������˵��:'��������,�ŵ��Ű�'��ֻ�����������죬���Ż�������,¶��һ�����������ĳ�������\n", this_player());
        set("exits/north", __DIR__"gate");
        remove_call_out("close");
        call_out("close", 10, this_object());

        return 1;
}

void close(object room)
{
        message("vision","������'�¸�'����������,�ѳ��ŵ�ס�ˡ�\n", room);
        room->delete("exits/north");
}

