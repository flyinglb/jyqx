// suti7.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
�յ���ʫ���ն��������ֿ�������ʱ�ú���Ͳ����ɵġ��ն���
����ʫ�������£�������Ǯ���غ��ˣ����ʿŮ�����ᡣ���ź����
���ϣ���ɽʼ������ͨ��������ʮ�����ɣ�����ϯ����̿ա�������
���Ǵ����������ӳ���š�ӳ�������յ������������ϵĵ�һ����
LONG);
        set("exits", ([
            "north"     : __DIR__"suti6",
            "south"     : __DIR__"road20",
        ]));
        set("objects", ([
            __DIR__"npc/shu-sheng" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
