// Room: /d/henshan/jigaoming.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������̨");
        set("long", @LONG
�����Ǹ�������ߴ����������������� "������" ���������ڴˣ�
�⼴���༫�� (���޼�����) ����⼫�� (����������) ������������
�ϵģ���Ի������̨��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"sansheng",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

