// zhanqiao.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ջ��");
        set("long", @LONG
ջ�������ϱ�Σ¥֮�䣬�����������̳ɣ�ÿ����������
�ڲ�����һ��ÿ������������ϣ�����ľ�壬����ʮ�ɣ�������
Ԩ��ɽ���Х�����Ķ��ǡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"   : __DIR__"xuankong2",
           "north"   : __DIR__"xuankong1",
        ]));
        set("outdoors", "hengshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
