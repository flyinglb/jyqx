// Room: /d/huashan/jzroad6.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����⣬��Ȼվ��һ�����ӣ�����ɭɭ�����ӱ��ϣ�ƾ��һ��ɷ
���������ǵ�ɽ��·�����߾ͽ���ɭ���ˡ�
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "enter"   : __DIR__"jzroad5",
            "westup"  : __DIR__"jzroad7",
        ]));
        set("objects", ([
             CLASS_D("huashan") + "/cheng-buyou": 1,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

