// Room: /d/mingjiao/mjfengmen1.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���������е�һ��СԺ����Ӱ������������������ϱ�����
һ�����ᣬ�����������͵��ͷ�ҵ��ӵ�����������
LONG );
    set("exits", ([
        "northwest" : __DIR__"mjfengmen",
	"north" : __DIR__"foshe",
	"south" : __DIR__"daoshe",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}

