// shantong.c ��ɽɽ��
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
������ȫ��̿�ɽ��ʦ���������˾��޵�ɽ���������󣬵�
���沼�õú����£�����˼ҵĿ���һ���������Ϲ���һ����
(hua)�����β輸���ܾ��¡�
LONG
        );
        set("exits", ([
                "out" : __DIR__"xiaolu12",
        ]));
        set("item_desc", ([
        "hua": "������һ�������ʿ�ı�Ӱ��������ʲô��ò��������һ��ָ�죬������
�š�"+MAG"��������"NOR+"���������֡�\n"
        ]) );

        set("objects", ([
                __DIR__"npc/wang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

