// Room: /u/zqb/tiezhang/hhyuan-3.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", YEL"��ɽ"NOR);
	set("long", @LONG
    ����ǰ������һ���޴�ļ�ɽ��һ��Ƭ��Ҳ�Ƶ����ٴӼ�ɽ��к 
��������ע��ǰ���һ��������У�����������������кˮͨ����������ˮ 
ȴ�������硣���ư�Ϊ�������԰��Ҳ��֪�����˶����������������ٲ��� 
�����ƺ���Լ�и�С�š�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hhyuan-1",
]));
	set("no_clean_up", 0);
    set("outdoors", "tiezhang");

	setup();
}

void init()
{
         add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if (arg !="�ٲ�") 
        return notify_fail("��Ҫ���Ķ�������\n");
        {
            write("���������ٲ���Ծȥ��\n");
                message("vision",
me->name() + "����һ��ͻȻ�����ˡ�\n",
                    environment(me), ({me}) );
            me->move(__DIR__"mishi");
            message("vision",me->name() + "���˹�����\n",                             
                    environment(me), ({me}) );
        }
        return 1;
}

