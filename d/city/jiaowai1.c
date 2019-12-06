// Room: /d/city/jiaowai1.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ݵ�");
    set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶
Ϧ�⣬������Ƣ�����Ǻ�ʱ�⡣ż�м���С��Ů���̤�࣬ݺ
����Ӱ�����ֶ��ˡ�
LONG );

    set("exits", ([
        "north" : __DIR__"dongmen",
        "south" : __DIR__"jiaowai2",
        "west"  : __DIR__"course",
        "east"  : __DIR__"bite",
    ]));

    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
    setup();
    create_door("east", "����С��", "west", DOOR_CLOSED);
    create_door("west", "����С��", "east", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
    me = this_player();
    if ((me->query("id")!="course" && me->query("id")!="qixia") && dir == "west")
    {
       return notify_fail(RED"�����˼ҵ�˽լ����ȥ�����ˣ�\n"NOR);
    }
    if ((me->query("id")!="bite" && me->query("id")!="princess") && dir == "east")
    {
       return notify_fail(RED"�����˼ҵ�˽լ����ȥ�����ˣ�\n"NOR);
    }
    return ::valid_leave(me, dir);
}

