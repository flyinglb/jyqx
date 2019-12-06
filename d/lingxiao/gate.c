//LUCAS 2000-6-18
// gate.c

inherit ROOM;

void init(); 
void close_bridge();
int do_close(string arg);
string look_bridge();
int do_open(string arg);
#include <ansi.h>;

void create()
{
        set("short", "��������");
        set("long", 
"�����������ǵĳ��š���������������������֣������ڵ�
������¡��֮�ʳ��ж���ǰ����Ϯ���������˴�������ֵ���
�������ȥ��ֻ����ͷ���������Ƿ������벻����������ѩɽ��
����ȴ����һ�����ȥ����\n"
 );
        set("outdoors", "lingxiao");

        set("exits", ([
                "eastup"  : __DIR__"walle1",
                "westup"  : __DIR__"wallw1",
                "north"  : __DIR__"iceroad1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 3,
        ]));
        setup();
} 

void init()
{
        add_action("do_open", "open"); 
        add_action("do_close", "close");
} 
void close_bridge()
{
        object room;

        if(!( room = find_object(__DIR__"shanya")) )
                room = load_object(__DIR__"shanya");
        if(objectp(room))
        {
                delete("exits/south");
                        message("vision", "�������Ӱѵ��Ź���������\n", this_object());
                room->delete("exits/north");
                message("vision", "ֻ��'�¸�'����,�����ֱ�����������\n", room);
        }
}
int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "bridge" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N��������������һ����,���ǵ��˵�ͷ,�ѵ��ŵ�����ȥ��\n", this_player());

        remove_call_out("close_bridge");
        call_out("close_bridge", 2);

        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("�����Ѿ��������ˡ�\n");

        if (!arg || (arg != "bridge" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"shanya")) )
                room = load_object(__DIR__"shanya");
        if(objectp(room))
        {
                set("exits/south", __DIR__"shanya");
                message_vision("$N���������Ӱѵ��ŷ���������\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "�¸¼���,���ŷ���������\n", room);
                remove_call_out("close_bridge");
                call_out("close_bridge", 10);
        }

        return 1;
}

string look_bridge()
{
        return "һ�ż���ĵ���,�������ǵ�һ�����ߡ�\n";
}

/*
int valid_leave(object me, string dir)
{
        if (dir == "north" )
        {
                if(me->query("family/family_name") !="������")
                {
                        if(me->query("combat_exp") >= 100)
                        {
                                if(present("wen wanfu", environment(me)) && living(present("wen wanfu", environment(me))))
                                {
                                        return notify_fail(
"�����ν��������η����˼���ֳǣ������˱����صء���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
                                }
                                else
                                        return ::valid_leave(me, dir);
                        }
                        else
                                return ::valid_leave(me, dir);
                }
                else
                        return ::valid_leave(me, dir);
        }
        else
                return ::valid_leave(me, dir);

}

*/