// /u/beyond/mr/cl4-1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ��Ҷ�
��������ȥ����æ���Լ������飬������һ�㵡����������һ��Сͤ�ӡ�
long);
         set("exits", ([
             "eastup" : __DIR__"tingzi",
             "west" : __DIR__"cl4",
]));
set("objects",([
__DIR__"npc/binu" : 2,
]));
         setup();
         replace_program(ROOM);
}

