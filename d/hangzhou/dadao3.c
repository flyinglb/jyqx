// dadao3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�غ����");
        set("long", @LONG
һ�����Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ�
�ˡ������羰����֮����ȴ�Ե�һƬ��ɪ��·��������һ��ׯ԰����
�����ϱ����졣
LONG);
        set("exits", ([
            "south"     : __DIR__"road19",
            "north"     : __DIR__"dalu1",
            "west"      : __DIR__"liuzhuang",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
}
