// shanbi.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����ǻ�ɽ�����ϵ�ɽ�ڡ�ɽ���ƺ��и�ɽ��(dong)��������һ
����ֻ����������һ���ŵ����Ʈ�����������룬ȴ�������ء�תͷ
�����������ڳ����Ŀ��������ֻ���ö�Ѩ���������С������
�겻��ȥ��
LONG );
        set("outdoors", "jinshe");
        set("exits", ([ /* sizeof() == 2 */
            "up" : "/d/huashan/ziqitai",
        ]));
        set("item_desc", ([
            "dong" : "һ���������ס��ɽ����\n"
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_break", "break");
}
int do_break(string arg)
{
//        int n;
//        object weapon,me=this_player();
        object me=this_player();
        if (arg != "dong") return 0;
        message_vision(HIY
"$N�ߵ�����ǰ������˫�ƣ��͵ػ������㣡\n"NOR,me);

        if (me->query("neili") < 100)
        {
               message_vision(HIY
"���ֻ��һ���ƺߣ�$N������ķ����������ǰһ��....\n"NOR,me);
               me->set("neili",0);
               me->unconcious();
               return 1;
        }
        message_vision(HIY
"$Nֻ��һ�����죬���㱻ͱ���ˣ�ԭ��������һ���󶴣�\n"NOR,me);
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
