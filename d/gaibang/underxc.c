// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ȳ�������");
        set("long", @LONG
���ǹȳ������ߵĹȶѣ����ܶ��Ǵ�ȶѡ����ܶ����˸�������
������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG
        );

        set("exits", ([
                "up" : "/d/village/square",
                "south":__DIR__"xcandao2",
        ]));

        set("objects",([
                  CLASS_D("gaibang") + "/ma-jw" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
