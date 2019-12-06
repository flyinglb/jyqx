// Room: wave.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","����");
        set("long",@LONG
�ߣ�һ������ˮͰ�ֵİ��ߣ��������ڱ������У���������
����������һ��ֱ���������³�Ѫ������ӣ���ֱ���˹�������
����һ���ȳ���ζ�����Ա�һ����ںܱ�����Լ�ɼ�������ʲô
������
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "out"  : __DIR__"wave2", 
        ])); 
        set("objects", ([
                __DIR__"npc/snake" : 1, 
        ]));
        setup();
}

void init()
{
        add_action("do_break", "break");
}
int do_break(string arg)
{
    object me;
    me=this_player();

    message_vision(HIC
"$N�ߵ�����ǰ���˾�����ں�ȥ��\n"NOR,me);

    if (me->query("neili") < 500)
    {
       message_vision(HIC
"���ֻ��һ���ƺߣ�$N�����ڵĺ������־���,��ǰһ��....\n"NOR,me);
       me->set("neili",0);
       me->unconcious();
       return 1;
    }
    message_vision(CYN
"$Nֻ��һ�����죬���ڱ��䴩�ˣ�¶��һ��С������\n"NOR,me);
    set("exits/enter",__DIR__"yudong");
    me->add("neili",-100);
    remove_call_out("close");
    call_out("close", 5, this_object());
    return 1;
}
void close_out()
{
    if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
    message("vision",HIC"һ�ɺ����Զ���ð�����������ֶ��˸�����ʵʵ��\n"NOR, room);
    room->delete("exits/enter");
}

