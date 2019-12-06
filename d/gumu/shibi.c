// shanbi.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����������ɽ�����ϵ�ɽ�ڡ�ɽ���ƺ��и�ɽ��(dong)��������һ
����ֻ����������һ���ŵ����Ʈ�����������룬ȴ�������ء�תͷ
�����������ڳ����Ŀ��������ֻ���ö�Ѩ���������С������
�겻��ȥ��
LONG );
        set("outdoors", "jinshe");
        /*
        set("exits", ([ 
		"up" : __DIR__"zhufeng",
        ]));
        */
        set("item_desc", ([
            "dong" : "һ����ʯ��(stone)��ס��ɽ����\n"
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_break", "break");
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();
        
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="up") )
                return 0;
        
        tell_room(environment(me),me->name()+"һת�������±�����ȥ������\n",({me}));
        tell_object(me,"��˳��ɽ������������ɽ����ȥ������\n\n");
        me->move(__DIR__"zhufeng");
        tell_room(environment(me),me->name()+"��֪���ǻ��˳��� ����\n",({me}));
        return 1;
}

int do_break(string arg)
{
        object me=this_player();
        if (arg != "stone") return 0;
        message_vision(HIY
"$N�ߵ�����ǰ������˫�ƣ��͵ػ����ʯ��\n"NOR,me);

        if (me->query("neili") < 100)
        {
               message_vision(HIY
"���ֻ��һ���ƺߣ�$N����ʯ�ķ����������ǰһ��....\n"NOR,me);
               me->set("neili",0);
               me->unconcious();
               return 1;
        }

        if(me->query_temp("tmark/��") < 2) {
               message_vision(HIY"���ֻ��һ�����죬$N����ʯ�ķ��������˫�ַ���....\n"NOR,me);
                return 1;
        }

        message_vision(HIY
"$Nֻ��һ�����죬��ʯ��ͱ���ˣ�ԭ��������һ���󶴣�\n"NOR,me);
        set("exits/enter",__DIR__"yongdao1");
        me->add("neili",-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        return 1;
}

void close(object room)
{
    message("vision","���Ϻ�Ȼ������һ������飬�����ڷ��˸�����ʵʵ��\n", room);
    room->delete("exits/enter");
}

int valid_leave(object me, string dir)
{
        if( dir=="enter" && ::valid_leave(me,dir) )
                 me->delete_temp("tmark/��");
        return ::valid_leave(me, dir);
}
