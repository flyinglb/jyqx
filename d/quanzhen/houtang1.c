// houtang1.c ����һ��
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����һ��");
        set("long", @LONG
�����Ǻ��õ�һ������ƽ��ȫ��̵�����Ϣ�ĵط�������ȫ���
���ڹ��յ��ӣ����аڷŵ�����Ҳ�������ӣ��Ե�������Ѿ���ӵ��
�ˡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"houtang2",
                "west" : __DIR__"laojundian",
        ]));

        setup();
        replace_program(ROOM);
}
