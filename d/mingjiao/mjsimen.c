// Room: /d/mingjiao/mjsimen.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��ʯ��");
    set("long", @LONG
����һƬС���֣���ǰ������һ������ʯ�������ֱͨ��
ǰ�����ص�ϡϡ��������ż��ð�����ȴ�Եøߴ�ͦ�Σ�������
��֦������ո߸���չ�š�
LONG );
    set("exits", ([
        "north" : __DIR__"tomen2",
        "south" : __DIR__"mjsimen1",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}

