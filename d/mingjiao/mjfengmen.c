// Room: /d/mingjiao/mjfengmen.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ����������
���ܵ����֡������˼�������Ω�����ߵ��·�棬ɮ��ľ������
���̵��¾���΢�紵����Ҷ�����������������˳���Ϊ֮һ�ӣ�
���Ǿ��ѵ��������ڡ�
LONG );
    set("exits", ([
        "northwest" : __DIR__"mjsimen1",
        "southeast" : __DIR__"mjfengmen1",
    ]));
    set("outdoors", "mingjiao");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

