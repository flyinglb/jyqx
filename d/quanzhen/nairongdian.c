// nairongdian.c ���ݵ�
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ݵ�");
        set("long", @LONG
�����Ǵ����Աߵ�һ����Ҳ�ǽӴ���Ҫ���˵ĵط����
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ��������
����ǽ���Ϲ���һЩ�ֻ���
LONG
        );
        set("exits", ([
                "south" : __DIR__"qingjing",
                "west" : __DIR__"piandian",
                "north" : __DIR__"datang3",
        ]));
        set("objects", ([
                __DIR__"npc/cheng" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
