//LUCAS 2000-6-18

// Room: car.c

inherit ROOM;
#include <ansi.h> 

int do_take(string arg);
void create()
{
        set("short","����");
        set("long",@LONG
�����������ǵı�����bing che����ɽ֮�����˱���������
��Ϊ����ֱ�����ݣ������ƶ��ɣ��ܴ���ѩɽ֮�۷��ٻ��£���
��ѩɽȥ�����ݵĽ�ͨ���ߡ�����Գ�����take�����������ݡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"iceroad3",
        ])); 
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 

        set("item_desc", ([
        "bing che": "һ̨���Ϻõĺ�ɼľ���Ƶı�����������������ɽ֮�á�\n"
        ]) );
        setup();
}  
void init()
{
        add_action("do_take", "take");
}


int do_take(string arg)
{
        object me=this_player();

        if( !arg || arg != "bing che" ) {
                return notify_fail("��Ҫ��ʲô��\n");
        }

        message_vision(HIW"$N���ȵ������ϱ��������������Ӵ�����ơ�\n�ǵ��ӵ��˵�ͷ��������һ�⣬������������֮�������·��������\n"NOR,this_player());
        message_vision(HIW"����ѩɽ��$N����Ź�����׾�֮�ţ�����֮�С�$N�����죬�̲�ס������Х��\n"NOR, this_player());

        me->move("/d/city/guangchang");

        return 1;
}

