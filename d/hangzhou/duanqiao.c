// duanqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������������������ķ�ˮ���ϡ�����ͤ�����䣬��ӳ����������֮�¡�
��ɽ��ˮ����������������������������������������ľ�ɫ���ڶ���
�Ͽ����������ɽ�ͺ�����ķ�⡣ÿ��ѩ�ᣬվ����ͷ��ֻ��һ�ж���
���ϰ�ѩ��������¥�ĺ�ɽ��ò��������ʮ��֮һ�ġ����Ų�ѩ���������
�������ߴ����еİ���������ɾ����������ġ�
    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ�����
LONG);
        set("exits", ([
            "northeast" : __DIR__"road9",
            "west"      : __DIR__"baiti",
        ]));
        set("objects", ([
            __DIR__"npc/poorman" : 1,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
