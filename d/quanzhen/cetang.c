// cetang.c ����
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǵ����Աߵ�һ��������Ҳ�ǽӴ���Ҫ���˵ĵط�������
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ������ɽʯ����
����ǽ���Ϲ���һЩ�ֻ���
LONG
        );
        set("exits", ([
                "east" : __DIR__"guozhendian",
                "west" : __DIR__"huizhentang",
                "north" : __DIR__"shiweishi",
                "south" : __DIR__"datang2",
        ]));
        set("objects", ([
                __DIR__"npc/li" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
