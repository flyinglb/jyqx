// fu-datang ���Ҵ���
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
�����Ǻ�Ա��ҵĴ��ã������Ϲ���һ����(bian)�����ڰ�
����һЩ�����������ӣ��ñ���÷����յ��������ҳ��������
÷���������Ҳ�����Ǹ�ӹ���ŵı��������ѡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"fu-ceting",
                "west" : __DIR__"fu-zhangfang",
                "north" : __DIR__"fu-xiaoyuan",
                "south" : __DIR__"fu-houyuan",
        ]));
        set("item_desc", ([
           "bian": HIR"
��������������������������
��������������������������
�������ҡ��塡�����ҡ�����
��������������������������
��������������������������
"NOR
        ]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
