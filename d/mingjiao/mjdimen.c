// Room: /d/mingjiao/mjdimen.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�ݵ�");
    set("long", @LONG
����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬����
��Ƣ������С����ݺ����Ӱ����Ƥ���ˣ����������������
��÷�����������������ǽ������ܣ��ߵ��������Ҳƽ��
�����ᣬ��ȴ����ɱ�⡣
LONG );
    set("exits", ([
        "northeast" : __DIR__"mjdimen1",
        "southwest" : __DIR__"mjsimen1",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}

