// chanfang1.c ����
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ��̵��Ӱڷű������������������ҵض���һЩ������
���Ѿ����ư߰��ˣ��еĻ��Ƿ���͸����ȫ�����������ʱ�򣬾͵�
��������ѡ���С�
LONG
        );
        set("exits", ([
                "east" : __DIR__"chanfang2",
        ]));
        set("objects", ([
                __DIR__"npc/obj/gangjian" : random(3),
                __DIR__"npc/obj/gangdao" : random(2),
                __DIR__"npc/obj/tiejia" : random(2),
        ]));

        setup();
        replace_program(ROOM);
}
