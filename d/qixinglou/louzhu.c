#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","ħ����");
    set("long",@LONG
��������¥¥�������Ļ���ң�ǽ�Ϲ���һ��ǧ����������ı�������δ���ʣ��Ѿ�ɱ�����ˡ�

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"liangong",
        "south" : __DIR__"chang",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
