// Room: /d/henshan/lingxingmen.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ĵ�һ���ţ��ɺ����񣬻���ʯ��͵�ʯ�Ʒ�����
����ɽ��ף����Ϣ֮�أ����̷�Ϊ����С���졣�ڴ�Զ����ɽ��ɽ����
�ɣ�����������յĴ���
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "north"  : __DIR__"kuixingge",
           "south"  : __DIR__"hengyang",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

