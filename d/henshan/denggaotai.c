// Room: /d/henshan/denggaotai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�Ǹ�̨");
        set("long", @LONG
�����������ŵǸ���Զ�ĺ�ȥ������վ�����������壬������
���衣���潭��ȥ������ű���ʱ��ʱ�֡���Χ��ϼ�����ޣ��ϸǣ���
����廷����������ǧ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"nantian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

