// pinghuqiuyue.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ƽ������");
        set("long", @LONG
ƽ������������ˮ�������������ȣ�ֱ�ڲ��ʡ����С������ƽ
���ƾ�����ʱ�º����������������д������ҹʱ��µ��յ�����
��ɫ���������߱��Ƿź�ͤ�����������ǰ׵̡����߾��ǹ�ɽ��
LONG);
        set("exits", ([
            "west"      : __DIR__"gushan",
            "northwest" : __DIR__"fangheting",
            "northeast" : __DIR__"baiti",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
