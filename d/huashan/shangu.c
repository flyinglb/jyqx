// Room: /d/huashan/shangu.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����������ɽ��һ������ɽ�ȡ������Ǹ߿ɼ����ɽ�壬������
�ܣ�һ��СϪ���������������������С�Ϫ����һ�����轣��������
���ŵ�Ϊ�
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "northdown" : __DIR__"jzroad7",
            "south"     : __DIR__"pingdi",
        ]));
        set("objects", ([
            CLASS_D("huashan")+"/cong-buqi": 1,
        ]));
        set("outdoors", "xx");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

