// Room: /d/henshan/nantian.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������ţ�����������ɽ��һ��ף�ڷ塣�������ǻ����ҵ�ʯ��
������������ "������" ���ֺ����Ҷ��ŵ�����ϣ��ֱ���� "��
��" �� "ʩ��" �����(lian)��ª���Լ������Ѿá�
LONG);
        set("exits", ([
            "northeast" : __DIR__"shiziyan",
            "southup"   : __DIR__"denggaotai",
            "eastup"    : __DIR__"liuyunping",
            "southwest" : __DIR__"shanlu13",
            "northwest" : __DIR__"shanlu14",
        ]));
        set("item_desc", ([
            "lian" :
"\n
        ��              ·
        ��              ��
        ͨ              ��
        ��              ��

        ��              ��
        ��              �
        ��              ��
        ��              ΢
        ��              ��
        ��              ��
        ��              ��\n\n",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
