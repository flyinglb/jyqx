#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","���¹�");
    set("long",@LONG
��������¥�������������¸��ˮ�ᾧ���޹������������¸��û����������
����������������ȥ����¥�����˵�С·��

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"dating2",
        "north" : __DIR__"liangong9",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
