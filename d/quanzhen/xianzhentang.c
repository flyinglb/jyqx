// xianzhentang.c ������
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ����Աߵ�һ��������Ҳ�ǽӴ���Ҫ���˵ĵط���������
ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ���ɽ��ˮ���辰��ǽ
���Ϲ���һЩ�ֻ���������һ��ҩ���ң�����ҩ�ĵط���
LONG
        );

        set("exits", ([
                "east" : __DIR__"piandian",
                "west" : __DIR__"yaojishi",
                "north" : __DIR__"datang1",
                "south" : __DIR__"rongwutang",
        ]));
        set("no_clean_up", 0);
        set("objects",([
              __DIR__"npc/zhang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
