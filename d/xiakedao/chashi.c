// Room: /d/xiakedao/chashi.c

#include <ansi.h>
inherit ROOM;

void init();
int do_sit(string);

void delete_served(object);

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ʯ������֦������ҫ��ȫ�������������������ˣ�һ
��ͯ��æǰæ�����ݵĹ���Ͳ��㣬������Ƣ���������ܵ����
����Щ����(table)������(chair)��
LONG );
        set("no_fight", 1);
        set("exits", ([
                "east" : __DIR__"neiting",
        ]));
        set("item_desc", ([
            "table" : "һ�ž��µ�ľ��С�����������һЩ��ߡ�\n",
            "chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ������Ү��\n",
        ]));

        set("objects",([
                __DIR__"npc/tongzi" : 1,
                "/d/wudang/obj/mitao" : 4,
                "/d/taohua/obj/cha" : 2,
        ]));
        setup();
}

void init()
{
        add_action("do_sit", "sit");
}

int do_sit(string arg)
{

        if ( !arg || (arg != "chair") )
                return notify_fail("��Ҫ��ʲô���棿\n");

        if (this_player()->query_temp("marks/sit"))
                return notify_fail("���Ѿ����˸���λ�ˡ�\n");

        this_player()->set_temp("marks/sit", 1);
        return notify_fail("�����˸���λ���£������ϲ衣\n");
}

/*
int valid_leave(object me, string dir)
{

        if (  (dir == "east")
           && ( present("xiang cha", this_player())
                || present("mi tao", this_player()) )
           && objectp(present("tongzi", environment(me))) )
        switch ( random(2) )
        {
        case 0:
         return notify_fail
                ("ͯ�Ӱ���һƲ���Ա��˺����˻����������߻��ﻹ����һЩ��\n");
        case 1:
         message_vision("ͯ�Ӷ�$N���˸����������Ը�����ʳ���ô����跿��", me);
         return notify_fail("\n");
         break;
        }

        me->delete_temp("marks/sit");
        me->delete_temp("tea_cup");
        return ::valid_leave(me, dir);
}
*/
