#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","����");
    set("long",@LONG
��������¥���õĶ�¥,��������¥����������ˮ�ᾧ���䣬
�����������������ȣ���֪����ȥ������Ǳ������ˣ���·�����ˡ�

LONG
    );
    set("sleep_room","1");
    set("exits",([
        "up"        : __DIR__"dating3",
        "down"      : __DIR__"dating1",
        "south"     : __DIR__"hufa",
        "east"      : __DIR__"chang4",
        "west"      : __DIR__"chang5",
        "north"     : __DIR__"tangzhu"
    ]));
    set("no_kill",1);
    set("no_fight",1);
    set("no_hit",1);
    set("steal",1);
    setup();
}
