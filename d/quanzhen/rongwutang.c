// rongwutang.c ������
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ������֮��̷���˵ľ��ң���䷿����ʰ�ĺ���ͨ����
��ûʲô����ֻ��һ����Ⱦ��ǽ��б����һ�ѱ�����
LONG
        );
        set("exits", ([
                "north" : __DIR__"xianzhentang",
        ]));
        set("objects",([
                __DIR__"npc/tan" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
