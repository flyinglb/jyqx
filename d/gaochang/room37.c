// Room: /u/mei/room37.c
// This is a room made by roommaker. write by Fan. :)
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
�ߵ����֮�󣬼���һ����С�ĵ��ã������龰ȴ��Ϊ�ɲ�����ʮ�ߺ���һ
�Ѷ��໥���ᣬ���Ǵ�ֱ������ʱ���е��������б��У��е�ȴ�ǿ��֡�
    ������һ��Сʯ�š�
LONG
    );
        set("objects", ([ 
  __DIR__"obj/skeleton" : 10,
]));
    set("exits", ([ 
       "south" : __DIR__"room36",
        "west" : __DIR__"room38",
    ]));
    create_door("west", "Сʯ��", "east", DOOR_CLOSED);
    setup();
}
