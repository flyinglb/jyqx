// wuchang1.c �䳡
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�䳡");
        set("long", @LONG
������ȫ��̵����䳡�����µ���ש�����̵��������룬ȴ
��֪����˭�ȳ��˼�ʮ�����СС�İ��ӡ����ĳ������������
���µ��е��������Ʒ��������쳤�վã����¾Ͳȳ��˰��ӡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "south" : __DIR__"wuchang2",
                "north" : __DIR__"houtang2",
                "southeast" : __DIR__"xiuxishi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
