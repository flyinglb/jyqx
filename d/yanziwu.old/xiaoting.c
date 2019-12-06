// Room: xiaoting

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string);
int do_sit(string);
void delete_served(object);

void create()
{
        set("short", "������");
        set("long", @LONG
����һ��С��,���䲻��,���õ�Ҳ���¡������ķ��㣬������Ƣ��
ֻ��ǽ�Ϲ��ż�������,������Ϊ����,���ڲ�ס��������֮����������
�ܾ��ɵذ���Щ����(table)������(chair)��
LONG );
        set("exits", ([
            "west" : __DIR__"qinyun",
            "east" : __DIR__"cuixia",
            "north" : __DIR__"xiaojing",
            "south" : __DIR__"chufang",
        ]));

        set("item_desc", ([
            "table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�\n",
            "chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ������Ү��\n",
        ]));

        set("objects",([
              __DIR__"npc/susu" : 1,
              __DIR__"obj/gao" : 2,
              __DIR__"obj/cha" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_tap", "tap");
        add_action("do_tap", "knock");
        add_action("do_sit", "sit");
}

int do_tap(string arg)
{

        object me;
        object susu;

        if (!arg || (arg != "desk" && arg != "table"))
        {
                return notify_fail("��Ҫ��ʲô��\n");
        }

        me = this_player();
        if( !objectp(susu = present("susu", environment(me))) )
                return notify_fail("�����������ӣ�ȴ����û�����㡣��ͻȻ�о��Լ������ġ�\n");

        if( !me->query_temp("marks/sit") )
                return notify_fail("�����������ӣ�ȴû�뵽�����������̴������������������ͨ��������"
                        +"\n�����㣬��ͻȻ�о��Լ����޴���\n");

        if( me->query_temp("marks/served") )
        {
            message_vision("���ز��ͷ��ض�$N˵�����ո����Ϲ�������ž�Ҫ��"+
                                "���Ǹ��ң�����ҿɲ��ǰ���\n", me);
            return notify_fail("");
        }

        message_vision("$N��������ǰ��������������棬����һЦ�������к���\n", me);

        susu->serve_tea(me) ;

        me->set_temp("marks/served", 1);
        call_out("delete_served", 10, me);

        return 1;
}


void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
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


int valid_leave(object me,string dir)
{
 //     if ( (dir =="north") ||(dir==south)||(dir==east)||(dir==west) )
        me->delete_temp("marks/sit");
        me->delete_temp("tea_cup");
        return::valid_leave(me,dir);
}
