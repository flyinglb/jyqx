// Room: /d/huashan/pingdi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��ƽ��");
        set("long", @LONG
����������ɽɽ��ƽ���ϡ�����ɽ������һС�ݡ����ŵ��껪ɽ
��Ů�彣�����ڴ�Ծ����мưܱ��Ľ��ڵ��Ӵ����������ɽ���ѵ�
���������������ᴵ���졣��ʧ��ĸо���
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"shangu",
            "east"  : __DIR__"xiaowu",
        ]));
        set("outdoors", "xx");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

