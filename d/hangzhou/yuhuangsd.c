// yuhuangsd.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ɽ��");
        set("long", @LONG
�������ɽ�����ɽ�£����Կ��������������˵���ǻʵۼ�
��ũʱ�׸��ļ��ɽ���и��ǹۣ�����Ƴ�������������һ�غͰ�
ʯ��������������ͤ���������߸���һ����ɽ��·��
LONG);
        set("exits", ([
            "eastdown"  : __DIR__"shanlu7",
            "westdown"  : __DIR__"shanlu6",
        ]));
        set("objects", ([
            __DIR__"honghua/yu" : 1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
