// Room: /d/mingjiao/mjleimen.c
// Jan.5 1997 By Venus

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��ʯ��");
    set("long", @LONG
����һƬ��ʯ�أ������޳���б�͵�ɨ��ʯ��ӳ�գ���Ӱ
ѩɽ�����������߱���Ŀ��ѩ������Ů���ڼ����Ҵ���ȥ��
�������Ҳ�������ܼ���
LONG );
    set("exits", ([
        "southwest" : __DIR__"mjleimen1",
        "northeast" : __DIR__"mjsimen1",
    ]));
    set("outdoors", "mingjiao");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
