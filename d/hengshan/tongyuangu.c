// Room: /d/hengshan/tongyuangu.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ͨԪ��");
        set("long", @LONG
ͨԪ�ȹ´����Է��£��ഫΪ�Ź��ϳ���ǰ�޵�֮����������
���� "ͨԪ" ������Ҳ�ͳ���ͨԪ�ȡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastup"  : __DIR__"guolaoling",
        ]));
        set("outdoors", "hengshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

