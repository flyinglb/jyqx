// wanwutang.c ������
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ������֮������һ�ľ��������䲻����ʰ��������
�࣬ǽ�Ϲ���һ��һ�ٺ�һЩ�ֻ���С���ϰڷ�����ֽ�ͻ�ī�Ǻ���
��֪��������Ҫ���ֻ��ǻ滭��
LONG
        );
        set("exits", ([
                "south" : __DIR__"huizhentang",
        ]));
        set("objects",([
                __DIR__"npc/wangchuyi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
