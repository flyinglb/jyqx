#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ϸ��");
        set("long", @LONG
������Ʈѩɽׯ�������ϵ����Ѵ�ľ����ǲ�ĵط���
��������ֻ�����ľ�ˣ����д��С�ĵ��
�ɱ���ˣ��ٺ�Ҫ���Ŷ��:)
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "south" : __DIR__"rest2",
        ]));
        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));
 
        setup();
        replace_program(ROOM);
}