// Room: /d/henshan/liuyunping.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ƺ");
        set("long", @LONG
ÿ���������ں�ɽ������������������ɽ����ӿ��������ɽ����
��ǰɽ��к��ֱ�����ӷ�к��εΪ׳�ۣ�����������ŵ������澰��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"  : __DIR__"nantian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

