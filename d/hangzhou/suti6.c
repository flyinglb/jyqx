// suti6.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
����֮ҹ�����¹ۺ��������������ԣ�����΢�磬���й���Ʈ�㣬
����Ϊ֮�����̱߲���С�������ο�ȥ��̶ӳ�µġ���������ȥ
���ۣ�����ɼ���̶ӳ��ң�����У������������ţ�����ӳ���š�
LONG);
        set("exits", ([
            "north"     : __DIR__"suti5",
            "south"     : __DIR__"suti7",
            "west"      : __DIR__"huagang",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
