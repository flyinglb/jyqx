// baimatang.c
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "����̶");
        set("long", @LONG
���̶Ϊ�����ɽ����һ����һ�����п����ӵ����Ρ�̶����һ
������䷿�ӻ�Ҫ��İ�ʯͷ����ʯͷ�м����ͷ�ߣ�ʯͷ��ǰ���
����ˮ��������ڰ��ϡ�������ˮ�е��ǰ��ʯͷ���滹��ʱð
��һ������ĭ����Զ��ȥ����һƥ�ڿ����ɵ�������˵����˶���
��̶Ϊ����̶��������һ����᫵�ɽ·��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northup" : __DIR__"shanlu6",
        ]));
        setup();
        replace_program(ROOM);
}
