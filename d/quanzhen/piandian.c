// piandian.c ƫ��
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ƫ��");
        set("long", @LONG
�����Ǵ����Աߵ�һ��������Ҳ�ǽӴ���Ҫ���˵ĵط�������
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ��������
����ǽ���Ϲ���һЩ�ֻ���
LONG
        );
        set("exits", ([
                "east" : __DIR__"nairongdian",
                "west" : __DIR__"xianzhentang",
                "north" : __DIR__"datang2",
                "south" : __DIR__"guangning",
        ]));
        set("objects", ([
                __DIR__"npc/shen" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
