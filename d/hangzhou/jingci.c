// jingci.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������ǰ���У���������м�Ĵ��۱�����Ϊ׳�ۡ����۱��
������㣬��ɫ�������ݶ����ر��Եľ�����ΰ�����ȵ������ڲ���ĺ
���лص������ﶯ�������������ʮ��֮һ���������ӡ���������
LONG);
        set("exits", ([
            "out"   : __DIR__"jingcisi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
