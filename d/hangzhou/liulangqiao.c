// liulangqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ÿ��������վ�����ϣ��غ������ڷ���ҡҷ����˷��գ���ݺ��
֦ͷӭ����Ϸ��������ת���ʵ�����������ݺ����
LONG);
        set("exits", ([
            "southwest" : __DIR__"jujingyuan",
        ]));
        set("objects", ([
            __DIR__"npc/maque" : 2,
            __DIR__"npc/wuya" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
