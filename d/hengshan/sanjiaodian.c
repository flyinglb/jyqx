// Room: /d/hengshan/sanjiaodian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���̵�");
        set("long", @LONG
������ȫ����ߴ������̵Ҳ�����������ĵ�������
����ȫ����ÿ��������ʯ��ľ�����ܣ����� "��������"�� �Ž���
����
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "down"   : __DIR__"xuankong1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
