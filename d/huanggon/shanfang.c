//shanfang.c ���ŷ�

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���ŷ�");
        set("long", @LONG
�ʹ������ʳ��ƽ��������Ȼ��ͬ,������Ǹ���������ŵ���
�ŷ�.�㲻������������ζ����һ��,�ɱ���������ǻʹ���.
LONG
        );
        set("objects", ([
        "/d/huanggon/obj/yuchi" : 2,
 "/d/huanggon/obj/nverhong" : 1,
        ]));
        setup();
}
