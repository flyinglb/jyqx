// yuefen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
Ĺ��������ʯ����ʯ��ʯ����������١����йŰؽ��£��������ɵķ�Ĺ��
Ĺ�����š���������Ĺ���� ����Ĺ�����棬��������֮�����Ƶ�Ĺ��Ĺ����
���š��μ��Һ�����֮Ĺ��.  ������ǰ�������ĸ�����(statue)������ǽ��
���ĸ�����(word)��
LONG);
        set("exits", ([
            "south"     : __DIR__"yuelang",
        ]));
        set("item_desc" , ([
            "statue" :
"�����������ػ�������������ϣ��ϱ�������ͬıɱ�����ɵļ鳼��
�ſ�����ٹм���ĸ����񶼷������֣�����Ĺ���š�\n",
            "word"   :
"ǽ���С����ұ������ĸ����֡�������ĸ����ѵ��ʱ�����ɱ��Ͽ̵��֡�\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
