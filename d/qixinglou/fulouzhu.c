#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","������");
    set("long",@LONG
��������¥��¥�����׵ľ���,�Ա���һ�������,���
��������׶��������ռ����书�ؼ����Ա߻���һ��������
�����յ���Ƭ,�Ա߻���һ̨ո�µ�VCD���϶�������������
�õġ�
LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"liangong2",
        "north" : __DIR__"chang",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
