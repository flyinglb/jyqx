// shangtianti.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�˴����գ������������������̽��ǰ���������Ǹߣ�����"������"��
��������ɽ��·���������ǽ����ء�������ȥ����ͨ�ﱱ����̨�塣
LONG );
        set("exits", ([ /* sizeof() == 4 */
           "southup"   : __DIR__"jinsuo",
           "northdown" : __DIR__"husun",
           "westup"    : __DIR__"canglong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}

