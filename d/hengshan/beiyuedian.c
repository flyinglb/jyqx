// Room: /d/hengshan/beiyuedian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ϸ����ڣ����ٹ��ݣ����Ƽ����죬�������£�񷱮ɭ
�������������������ң����顰��Ԫ֮������ڱ�����ɽ֮��ȫ
�����񣬸߿����ࡣ
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westup"    : __DIR__"huixiantai",
           "eastup"    : __DIR__"yuyang",
           "northup"   : __DIR__"shandao1",
           "southdown" : __DIR__"beiyuemiao",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

