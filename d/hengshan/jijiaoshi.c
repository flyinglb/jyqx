// Room: /d/hengshan/jijiaoshi.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ʯ");
        set("long", @LONG
����������࣬��һ���������ʯͷ���Ƽ���ʯ����֮�� "��
��" �����������������峿�û�������ɽ�Ȼ�������Ⱥ����������
�� "�𼦱���" ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "east"  : __DIR__"beiyuemiao",
        ]));
        set("outdoors", "hengshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

