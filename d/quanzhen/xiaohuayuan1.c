// xiaohuayuan1.c С��԰
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
���������������С��԰��������Ʈ��һ���ʻ�����ζ������
��ȥ�����ǽ�����ˡ������԰����ȴ��ȫ�����������϶�
������ĵط���԰�м�����һ���Ӳݣ�Ҳ��ר�����˸���������
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southwest" : __DIR__"houtang3",
                "northeast" : __DIR__"xiaohuayuan2",
        ]));

        set("objects", ([
                __DIR__"npc/zhangyuan" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
