// hupaoquan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
ֻ��Ȫˮ��ɳ���������������峺���ס��ഫ��λ�����Կյĺ�
�����ɽ�羰���㣬��ס������������ˮԴ��ȱ��׼��Ǩ�ߡ�һҹ��
���������˵��������ɽͯ��Ȫ����ǲ�������������ڶ��죬��Ȼ��
����ֻ�ϻ��ܵ���Ѩ��ӿ��Ȫˮ�����Զ���Ϊ������Ȫ����
LONG);
        set("exits", ([
            "east"    : __DIR__"road17",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
