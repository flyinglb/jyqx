// Room: /d/mingjiao/mjsimen1.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�㳡");
    set("long", @LONG
������һƬͥԺ����Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ�
��Ϊƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�
϶�г��˳������㳡�����м���С����ͨ�����̵ġ���ط��ס�
���š�
LONG );
    set("exits", ([
        "north"     : __DIR__"mjsimen",
        "northwest" : __DIR__"mjtianmen",
        "northeast" : __DIR__"mjdimen",
        "southeast" : __DIR__"mjfengmen",
        "southwest" : __DIR__"mjleimen",
    ]));
    set("outdoors", "mingjiao");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

