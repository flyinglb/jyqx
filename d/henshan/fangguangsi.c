// Room: /d/henshan/fangguangsi.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������������¡��������а˸�ɽͷ�����������꣬�����¾�
�������������ĵ�һƬƽ���ϡ��������ţ��� "���η����£���֪����
֮��" ֮˵���� "������֮��" Ϊ��ɽ���ľ�֮һ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanjian",
           "eastup"     : __DIR__"shanlu10",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

