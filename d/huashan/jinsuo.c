// jinsuo.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ɽ������һ������������һƬ�����أ������Ǹ������Ƶ��ͱڣ��м�
һ����С��������һ�򵱹أ����Ī����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
           "southup"   : __DIR__"zhenyue",
           "northdown" : __DIR__"shangtianti",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}

