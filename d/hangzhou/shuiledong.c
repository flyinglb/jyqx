// shuiledong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ˮ�ֶ�");
        set("long", @LONG
ˮ�ֶ����������ڣ���������й�ɽȪ��ʯ����ӿ����Ȫˮ����
��ʯ����г�ö������С���Ȼ�����������������١���ʯ���־䡣��
�������кܶ�����ʯ����������ɽ��·�����ϱ㵽����ϼ����
LONG);
        set("exits", ([
                "westup"    : __DIR__"yanxiadong",
                "eastdown"  : __DIR__"manjuelong",
        ]));
        set("resource/water", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
